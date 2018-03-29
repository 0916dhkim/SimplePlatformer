#ifndef SIMPLEPLATFORMER_ENGINE_SCENE_H
#define SIMPLEPLATFORMER_ENGINE_SCENE_H
#include <string>
#include <vector>
#include <engine/gameobject.h>
// Scene class holds game objects to be instantiated.
class Scene {
 public:
  std::string GetName() const;
  explicit Scene(const std::string &name);
 private:
  // Scene name
  const std::string name;

  // Collection of all game objects in this scene.
  std::vector<GameObject> gameobjects;
};
#endif //SIMPLEPLATFORMER_ENGINE_SCENE_H
