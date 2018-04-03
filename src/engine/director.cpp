#include <engine/director.hpp>
const float Director::kLoopInterval = 1.0f / 60.0f;

std::pair<std::map<std::string, Scene>::iterator, bool>
Director::AddScene(const std::string &name) {
  return Director::Get().scenes.emplace(
      std::pair<std::string, Scene>(name, Scene()));
}
std::pair<std::map<std::string, Scene>::iterator, bool>
Director::AddScene(const std::string &name, const Scene &scene) {
  return Director::Get().scenes.emplace(
      std::pair<std::string, Scene>(name, scene));
}

Allegro5Wrapper &Director::Allegro() { return Director::Get().allegro; }

void Director::LoadScene(const std::string &name) {
  auto res = Director::Get().scenes.find(name);
  if (res != Director::Get().scenes.end()) {
    // Scene found.
    Director::Get().stage.LoadScene(res->second);
  }
  // Scene not found.
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
