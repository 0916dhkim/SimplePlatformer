#include <engine/director.hpp>
#include <engine/event/event_contact.hpp>
#include <engine/event/event_key_down.hpp>
Director::Director() : dt(), world(b2Vec2(0, 0)) { debug_font = allegro.LoadFont("Lato/Lato-Regular.ttf", 12); }

const double Director::kLoopInterval = 1.0 / 120.0;
const int Director::kPhysicsVelocityIterations = 8;
const int Director::kPhysicsPositionIterations = 3;

Allegro5Wrapper &Director::Allegro() { return Director::Get().allegro; }

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
    b2Contact *contact = Get().world.GetContactList();
    while (contact) {
      // Handle contacts.
      std::uint_fast64_t id_a = PhysicalBody::GetUserData(contact->GetFixtureA()->GetBody());
      std::uint_fast64_t id_b = PhysicalBody::GetUserData(contact->GetFixtureB()->GetBody());
      std::shared_ptr<Actor> actor_a = Get().stage.GetActor(id_a);
      std::shared_ptr<Actor> actor_b = Get().stage.GetActor(id_b);
      EventContact event_a = {id_b};
      EventContact event_b = {id_a};
      if (actor_a)
        actor_a->HandleContactEvent(event_a);
      if (actor_b)
        actor_b->HandleContactEvent(event_b);
      contact = contact->GetNext();
    }

    // Handle events.
    auto actors = Get().stage.GetActors(); // Pair of begin and end of actor map.
    auto ev = Director::Get().allegro.WaitForEventTimed(kLoopInterval);
    if (ev != nullptr) {
      if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        // Window close event.
        break;
      } else if (ev->type == ALLEGRO_EVENT_KEY_DOWN) {
        // Key down event.
        EventKeyDown e = {static_cast<KeyCode>(ev->keyboard.keycode)};
        for (auto it = actors.first; it != actors.second; ++it) {
          it->second->HandleKeyDownEvent(e);
        }
      }
    }
    for (auto it = actors.first; it != actors.second; ++it) {
      // Update method is called evey frame.
      it->second->Update();
    }

    Get().Render();
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
  auto actors = Get().stage.GetActors();
  for (; actors.first != actors.second; actors.first++) {
    actors.first->second->UpdateActorTransform();
  }
}

void Director::Render() {
  Director::Get().Allegro().ClearToColor(Color::BLACK); // Clear to black

  // Render all actors.
  auto actors = Get().stage.GetActors();
  for (; actors.first != actors.second; actors.first++) {
    actors.first->second->Render(Get().stage.GetCamera());
  }

  // Display fps.
  allegro.DrawText(debug_font, Color::WHITE, 1, 1, Alignment::ALIGN_LEFT, std::to_string(1.0 / dt.count()));

  Director::Get().allegro.FlipDisplay();
}
