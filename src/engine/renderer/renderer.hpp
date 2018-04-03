#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
#include <engine/camera.hpp>
#include <engine/gameobject.hpp>
#include <engine/transform.hpp>
struct GameObject;
// Abstract class
class Renderer {
public:
  virtual ~Renderer(){};
  virtual void Render(const Transform &object_transform,
                      const Camera &camera) const = 0;

protected:
  static Transform::Position VertexCoordinate(const Transform &object_transform,
                                              const Camera &camera,
                                              const Transform::Position p,
                                              const float &width,
                                              const float &height);
  static Transform::Position LocalToWorld(const Transform &object_transform,
                                          const Transform::Position &p);
  static Transform::Position WorldToScreen(const Camera &camera,
                                           const Transform::Position &p);
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_RENDERER_H
