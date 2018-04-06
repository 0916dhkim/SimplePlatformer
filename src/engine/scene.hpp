#ifndef SIMPLEPLATFORMER_ENGINE_SCENE_H
#define SIMPLEPLATFORMER_ENGINE_SCENE_H
#include <engine/stage.hpp>
class Scene {
public:
  virtual void Play(Stage &stage) const = 0;
};
#endif // SIMPLEPLATFORMER_ENGINE_SCENE_H
