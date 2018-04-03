#include <engine/stage.hpp>
unsigned long Stage::AddGameObject(const GameObject &gameobject) {
  // Assign ID number.
  static unsigned long next_id = 1;
  unsigned long current_id = next_id++;
  auto res = actors.emplace(std::make_pair(
      current_id, std::make_shared<Actor>(next_id++, gameobject)));
  if (res.second) {
    // Insert success.
    return res.first->first;
  }

  // Insert fail.
  return 0;
}
void Stage::Clear() {
  // Remove actors.
  actors.clear();
}

void Stage::LoadScene(const Scene &scene) {
  // Clear the stage.
  Clear();

  // Change camera.
  camera = scene.camera;

  // Put game objects on stage.
  for (GameObject gameobject : scene.gameobjects) {
    AddGameObject(gameobject);
  }
}

void Stage::Render() const {
  for (auto a : actors) {
    a.second->Render(camera);
  }
}
