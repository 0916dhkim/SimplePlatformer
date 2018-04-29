#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/actor.hpp>
#include <engine/camera.hpp>
#include <memory>
class Actor;
class Transform;
// Abstract class
class Renderer {
public:
  Renderer(Actor &actor, const b2Vec2 &pivot);
  virtual ~Renderer() {}
  virtual void Render(const Camera &camera) const = 0;

protected:
  Actor &actor;
  b2Vec2 pivot;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
