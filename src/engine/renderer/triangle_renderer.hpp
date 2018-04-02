#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#include <engine/renderer/renderer.hpp>
#include <engine/color.hpp>
// Primitive renderer class that renders a equilateral triangle.
class TriangleRenderer : Renderer {
 public:
  void Render(GameObject gameobject) const override;
  TriangleRenderer(float sideLength, Color color);

 private:
  // Color of triangle
  Color color;

  // Length of one side of the equilateral triangle.
  float sideLength = 1;
};
#endif  // SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
