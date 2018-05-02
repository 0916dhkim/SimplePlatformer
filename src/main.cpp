#include <engine.hpp>
#include <game/main_scene.hpp>

int main() {
  Director::LoadScene(MainScene());
  Director::Start();
  return 0;
}
