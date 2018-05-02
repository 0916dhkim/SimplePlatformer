#include <engine/director.hpp>
#include <queue>
Director::Director() : dt(), world(b2Vec2(0, 0)) {
  world.SetContactListener(this);
  debug_font = allegro.LoadFont("Lato/Lato-Regular.ttf", 12);
}

const double Director::kLoopInterval = 1.0 / 120.0;
const int Director::kPhysicsVelocityIterations = 8;
const int Director::kPhysicsPositionIterations = 3;

Allegro5Wrapper &Director::Allegro() { return Director::Get().allegro; }

std::weak_ptr<Actor> Director::GetActor(std::uint_fast64_t id) { return Get().stage.GetActor(id); }

Camera &Director::GetCamera() { return Get().stage.GetCamera(); }

b2World &Director::GetWorld() { return Director::Get().world; }

void Director::LoadScene(const Scene &scene) { scene.Play(Director::Get().stage); }

void Director::Start() {
  // Start taking time.
  Director::Get().timestamp = std::chrono::steady_clock::now();

  while (true) {
    // Calculate delta t.
    auto now = std::chrono::steady_clock::now();
    Get().dt = now - Get().timestamp;
    Get().timestamp = now;

    Get().SimulatePhysics();

    // Handle events.
    std::vector<std::weak_ptr<Actor>> actors = Get().stage.GetActors();
    auto ev = Director::Get().allegro.WaitForEventTimed(kLoopInterval);
    if (ev != nullptr) {
      bool close = false;
      switch (ev->type) {
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        close = true;
        break;
      case ALLEGRO_EVENT_KEY_DOWN: {
        EventKeyDown e = {static_cast<KeyCode>(ev->keyboard.keycode)};
        for (auto actor : actors) {
          if (!actor.expired()) {
            actor.lock()->HandleKeyDownEvent(e);
          }
        }
        break;
      }
      case ALLEGRO_EVENT_KEY_UP: {
        EventKeyUp e = {static_cast<KeyCode>(ev->keyboard.keycode)};
        for (auto actor : actors) {
          if (!actor.expired()) {
            actor.lock()->HandleKeyUpEvent(e);
          }
        }
        break;
      }
      default:
        break;
      }
      if (close) {
        break;
      }
    }
    for (auto actor : actors) {
      if (!actor.expired()) {
        actor.lock()->Update();
      }
    }

    Get().Render();
  }
}

void Director::BeginContact(b2Contact *contact) {
  std::uint_fast64_t id_a = PhysicalBody::GetUserData(contact->GetFixtureA()->GetBody());
  std::uint_fast64_t id_b = PhysicalBody::GetUserData(contact->GetFixtureB()->GetBody());
  std::shared_ptr<Actor> actor_a = stage.GetActor(id_a).lock();
  std::shared_ptr<Actor> actor_b = stage.GetActor(id_b).lock();
  EventBeginContact event_a{id_b};
  EventBeginContact event_b{id_a};
  if (actor_a) {
    actor_a->HandleBeginContactEvent(event_a);
  }
  if (actor_b) {
    actor_b->HandleBeginContactEvent(event_b);
  }
}

void Director::EndContact(b2Contact *contact) {
  std::uint_fast64_t id_a = PhysicalBody::GetUserData(contact->GetFixtureA()->GetBody());
  std::uint_fast64_t id_b = PhysicalBody::GetUserData(contact->GetFixtureB()->GetBody());
  std::weak_ptr<Actor> actor_a = stage.GetActor(id_a);
  std::weak_ptr<Actor> actor_b = stage.GetActor(id_b);
  EventEndContact event_a{id_b};
  EventEndContact event_b{id_a};
  if (!actor_a.expired()) {
    actor_a.lock()->HandleEndContact(event_a);
  }
  if (!actor_b.expired()) {
    actor_b.lock()->HandleEndContact(event_b);
  }
}

Director &Director::Get() {
  static Director instance;
  return instance;
}

void Director::SimulatePhysics() {
  // Box2D simulation.
  Director::Get().world.Step(Director::Get().dt.count(), kPhysicsVelocityIterations, kPhysicsPositionIterations);

  // Update actor transforms.
  std::vector<std::weak_ptr<Actor>> actors = Get().stage.GetActors();
  for (auto actor : actors) {
    if (!actor.expired()) {
      actor.lock()->UpdateActorTransform();
    }
  }
}

struct ActorComparatorByLayer {
  bool operator()(std::shared_ptr<Actor> a, std::shared_ptr<Actor> b) { return a->layer < b->layer; };
};

void Director::Render() {
  Director::Get().Allegro().ClearToColor(Color::BLACK); // Clear to black

  // Render all actors.
  std::priority_queue<std::shared_ptr<Actor>, std::vector<std::shared_ptr<Actor>>, ActorComparatorByLayer> render_queue;
  auto actors = Get().stage.GetActors();
  for (auto actor : actors) {
    // Add all actors to render queue.
    if (!actor.expired()) {
      render_queue.push(actor.lock());
    }
  }
  while (!render_queue.empty()) {
    render_queue.top()->Render(Get().stage.GetCamera());
    render_queue.pop();
  }

  // Display fps.
  allegro.DrawText(debug_font, Color::WHITE, 1, 1, Alignment::ALIGN_LEFT, std::to_string(1.0 / dt.count()));

  Director::Get().allegro.FlipDisplay();
}
