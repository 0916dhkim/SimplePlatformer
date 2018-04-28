#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/camera.hpp>
#include <engine/transform.hpp>
class Actor;
class Transform;
// Abstract class
class Renderer {
public:
  Renderer(Transform &transform, const b2Vec2 &pivot);
  virtual ~Renderer() {}
  virtual void Render(const Camera &camera) const = 0;

protected:
  const Transform &GetTransform() const;
  Transform &GetTransform();
  b2Vec2 pivot;

private:
  Transform &transform;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
