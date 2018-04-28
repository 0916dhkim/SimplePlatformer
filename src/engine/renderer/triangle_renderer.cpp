#include <cmath>
#include <engine/director.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <utility>
TriangleRenderer::TriangleRenderer(Transform& transform, float sideLength, const b2Vec2& pivot, const Color& color) : Renderer(transform, pivot), sideLength(sideLength), color(color)
{
}

void TriangleRenderer::Render(const Camera &camera) const {
  // Find where vertices are.
  float w = sideLength;
  float h = sideLength * std::sqrt(3) / 2.0f;
  std::array<b2Vec2, 3> vertices = {b2Vec2(0, 0), b2Vec2(w / 2.0f, h), b2Vec2(w, 0)};
  for (b2Vec2 &v : vertices) {
    // Apply pivot.
    v.x -= w*pivot.x;
    v.y -= h*pivot.y;
    // Calculate screen coordinates.
    v = GetTransform().ToScreen(v, camera);
  }

  // Render.
  Director::Allegro().DrawFilledTriangle(vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y,
                                         color);
}
