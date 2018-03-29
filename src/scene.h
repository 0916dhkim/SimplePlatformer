#ifndef SIMPLEPLATFORMER_SCENE_H
#define SIMPLEPLATFORMER_SCENE_H
#include <string>
#include <vector>
#include <gameobject.h>
// Scene class holds game objects to be instantiated.
class Scene {
 public:
  std::string GetName() const;
 private:
  // Scene name
  const std::string name;

  // Collection of all game objects in this scene.
  std::vector<GameObject> gameobjects;
};
#endif //SIMPLEPLATFORMER_SCENE_H
