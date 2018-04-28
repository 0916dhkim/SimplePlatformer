#include <engine/director.hpp>
#include <engine/renderer/line_renderer.hpp>
LineRenderer::LineRenderer(Transform &transform, const b2Vec2 &pivot, float length, const Color &color)
    : Renderer(transform, pivot), length(length), color(color) {}

void LineRenderer::Render(const Camera &camera) const {
  b2Vec2 pivot_point(length * pivot.x, 0);
  b2Vec2 p1 = GetTransform().ToScreen(b2Vec2(0, 0) - pivot_point, camera);
  b2Vec2 p2 = GetTransform().ToScreen(b2Vec2(length, 0) - pivot_point, camera);

  Director::Allegro().DrawLine(p1.x, p1.y, p2.x, p2.y, color, 1);
}
