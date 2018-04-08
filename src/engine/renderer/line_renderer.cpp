#include <engine/director.hpp>
#include <engine/renderer/line_renderer.hpp>
LineRenderer::LineRenderer(float length, const Color &color)
    : length(length), color(color) {}

void LineRenderer::Render(const Transform &object_transform,
                          const Camera &camera) const {
  b2Vec2 p1(0, 0);
  b2Vec2 p2(length, 0);
  p1 = VertexCoordinate(object_transform, camera, p1, length, 0);
  p2 = VertexCoordinate(object_transform, camera, p2, length, 0);
  Director::Allegro().DrawLine(p1.x, p1.y, p2.x, p2.y, color, 1);
}
