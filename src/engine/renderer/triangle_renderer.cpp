#include <cmath>
#include <engine/allegro5_wrapper.hpp>
#include <engine/director.hpp>
#include <engine/renderer/triangle_renderer.hpp>
TriangleRenderer::TriangleRenderer(float sideLength, Color color)
    : color(color), sideLength(sideLength) {}

void TriangleRenderer::Render(GameObject gameobject) const {
  // Calculate the coordinates of the triangle.
  const float pi = atan(1.0f) * 4.0f;
  float x[3];
  float y[3];

  float theta = pi / 2.0f + gameobject.transform.rotation;
  float armLength = 2.0f * sideLength / sqrt(3.0f);
  for (int i = 0; i < 3; i++) {
    x[i] = armLength * cos(theta);
    y[i] = armLength * sin(theta);
    theta += 2.0f * pi / 3.0f;
  }

  // Render.
  Director::Allegro().DrawFilledTriangle(x[0], y[0], x[1], y[1], x[2], y[2],
                                         color);
}
