#include <engine/director.hpp>
#include <game/main_scene.hpp>

int main(int argc, char **argv) {
  const Scene &s = MainScene();
  Director::AddScene("main", s);
  Director::LoadScene("main");
  Director::Start();
  return 0;
}
