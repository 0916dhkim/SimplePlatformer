#include <cmath>
#include <engine/allegro5_wrapper.hpp>
#include <engine/director.hpp>
#include <engine/renderer/triangle_renderer.hpp>
TriangleRenderer::TriangleRenderer(float sideLength, Color color)
    : color(color), sideLength(sideLength) {}

void TriangleRenderer::Render(GameObject gameobject) const {
  // Calculate the coordinates of the triangle.
  std::array<std::pair<float, float>, 3> points = {
      {{0, 0},
       {sideLength, 0},
       {sideLength * sqrt(3.0f) / 2.0f, sideLength / 2.0f}}};

  for (std::pair<float, float> &p : points) {
    p = gameobject.transform.TransformPoint(
        p, {sideLength, sideLength * sqrt(3.0f) / 2.0f});
  }

  // Render.
  Director::Allegro().DrawFilledTriangle(
      points[0].first, points[0].second, points[1].first, points[1].second,
      points[2].first, points[2].second, color);
}
