#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/gameobject.hpp>
// Abstract class
class Renderer {
 public:
  virtual ~Renderer(){};
  virtual void Render(GameObject gameobject) const = 0;
};
#endif  // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
