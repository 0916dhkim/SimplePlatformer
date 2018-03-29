#include <engine/director.h>
const float Director::kLoopInterval = 1.0f/60.0f;

Scene &Director::AddScene(const std::string &name){
  Director::Get().scenes.emplace_back(name);
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

Director &Director::Get() {
  static Director instance;
  return instance;
}