#include <engine/director.h>
const float Director::kLoopInterval = 1.0f / 60.0f;

std::pair<std::map<std::string, Scene>::iterator, bool> Director::AddScene(
    const std::string& name) {
  return Director::Get().scenes.emplace(
      std::pair<std::string, Scene>(name, Scene()));
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

    Director::Get().allegro.FlipDisplay();
  }
}

Director& Director::Get() {
  static Director instance;
  return instance;
}
