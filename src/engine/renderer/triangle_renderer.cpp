#include <cmath>
#include <engine/director.hpp>
#include <engine/renderable/triangle_attribute.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <utility>
TriangleRenderer::TriangleRenderer(const GameObject &gameobject)
    : renderable(gameobject.renderable) {}

void TriangleRenderer::Render(const Transform &object_transform,
                              const Camera &camera) const {
  std::array<Transform::Position, 3> vertices;
  float w = renderable.attribute.triangle.side_length;
  float h = w * std::sqrt(3.0f) / 2.0f;
  vertices[0].x = 0;
  vertices[0].y = 0;
  vertices[1].x = w / 2.0f;
  vertices[1].y = h;
  vertices[2].x = w;
  vertices[2].y = 0;
  for (Transform::Position &v : vertices) {
    v = VertexCoordinate(object_transform, camera, v, w, h);
  }

  // Render triangle.
  Director::Allegro().DrawFilledTriangle(
      vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x,
      vertices[2].y, renderable.attribute.triangle.color);
}
