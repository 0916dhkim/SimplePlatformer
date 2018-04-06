#include <engine/director.hpp>
const float Director::kLoopInterval = 1.0f / 60.0f;

Allegro5Wrapper &Director::Allegro() { return Director::Get().allegro; }

void Director::LoadScene(const Scene &scene) {
  scene.Play(Director::Get().stage);
}

void Director::Start() {
  while (true) {
    // Handle events.
    auto ev = Director::Get().allegro.WaitForEventTimed(kLoopInterval);

    if (ev != nullptr) {
      if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        // Window close event fired.
        break;
      }
    }

    // Render objects.
    Director::Get().stage.Render();
    Director::Get().allegro.FlipDisplay();
  }
}

Director &Director::Get() {
  static Director instance;
  return instance;
}
