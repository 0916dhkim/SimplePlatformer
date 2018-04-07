#include <engine/convert.hpp>
#include <engine/renderer/renderer.hpp>
b2Vec2 Renderer::VertexCoordinate(const Transform &object_transform,
                                  const Camera &camera, const b2Vec2 p,
                                  const float &width, const float &height) {
  b2Vec2 ret =
      Convert::TransformCoordinates(object_transform, p, width, height);

  ret = Convert::LocalToWorld(object_transform, ret);
  ret = Convert::WorldToScreen(camera, ret);

  return ret;
}
