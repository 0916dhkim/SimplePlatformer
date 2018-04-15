#include <engine/director.hpp>
Director::Director() : world(b2Vec2(0, 0)), dt() {}

const float Director::kLoopInterval = 1.0f / 60.0f;
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
    Director::Get().dt =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - Director::Get().timestamp);

    // Handle events.
    auto ev = Director::Get().allegro.WaitForEventTimed(kLoopInterval);

    if (ev != nullptr) {
      if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        // Window close event fired.
        break;
      }
    }

    Get().SimulatePhysics();
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
  Director::Get().Allegro().ClearToColor({0, 0, 0, 255}); // Clear to black

  // Render all actors.
  auto actors = Get().stage.GetActors();
  for (; actors.first != actors.second; actors.first++) {
    actors.first->second->Render(Get().stage.GetCamera());
  }

  Director::Get().allegro.FlipDisplay();
}
