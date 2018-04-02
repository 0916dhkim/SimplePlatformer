#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/gameobject.hpp>
// Abstract class
class Renderer {
 public:
  virtual void Render(GameObject gameobject) const;
};
#endif  // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
