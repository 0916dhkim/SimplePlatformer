#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/camera.hpp>
#include <engine/transform.hpp>
struct GameObject;
// Abstract class
class Renderer {
public:
  virtual ~Renderer() {}
  virtual void Render(const Transform &object_transform,
                      const Camera &camera) const = 0;

protected:
  static b2Vec2 VertexCoordinate(const Transform &object_transform,
                                 const Camera &camera, const b2Vec2 p,
                                 const float &width, const float &height);
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
