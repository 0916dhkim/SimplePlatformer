#ifndef SIMPLEPLATFORMER_ENGINE_SCENE_H
#define SIMPLEPLATFORMER_ENGINE_SCENE_H
#include <engine/gameobject.hpp>
#include <string>
#include <vector>
// Scene class holds game objects to be instantiated.
class Scene {
 public:
  Scene();

 private:
  // Collection of all game objects in this scene.
  std::vector<GameObject> gameobjects;
};
#endif  // SIMPLEPLATFORMER_ENGINE_SCENE_H
