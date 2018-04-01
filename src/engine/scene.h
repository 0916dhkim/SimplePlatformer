#ifndef SIMPLEPLATFORMER_ENGINE_SCENE_H
#define SIMPLEPLATFORMER_ENGINE_SCENE_H
#include <string>
#include <vector>
#include <engine/gameobject.h>
// Scene class holds game objects to be instantiated.
class Scene {
 public:
  Scene();
 private:
  // Collection of all game objects in this scene.
  std::vector<GameObject> gameobjects;
};
#endif //SIMPLEPLATFORMER_ENGINE_SCENE_H
