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
  static Vector2 VertexCoordinate(const Transform &object_transform,
                                  const Camera &camera, const Vector2 p,
                                  const float &width, const float &height);
  static Vector2 LocalToWorld(const Transform &object_transform,
                              const Vector2 &p);
  static Vector2 WorldToScreen(const Camera &camera, const Vector2 &p);
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
