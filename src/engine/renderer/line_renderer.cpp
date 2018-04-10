#include <engine/director.hpp>
#include <engine/renderer/line_renderer.hpp>
LineRenderer::LineRenderer(Transform &transform, float length, const Color &color)
    : Renderer(transform), length(length), color(color) {}

void LineRenderer::Render(const Camera &camera) const {
  b2Vec2 p1 = GetTransform().ToScreen(b2Vec2(0, 0), camera);
  b2Vec2 p2 = GetTransform().ToScreen(b2Vec2(length, 0), camera);

  Director::Allegro().DrawLine(p1.x, p1.y, p2.x, p2.y, color, 1);
}
