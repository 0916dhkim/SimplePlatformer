#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#include <engine/color.hpp>
#include <engine/renderer/renderer.hpp>
// Primitive renderer class that renders a equilateral triangle.
class TriangleRenderer : public Renderer {
public:
  TriangleRenderer(Transform &transform, float sideLength, const Color &color);
  void Render(const Camera &camera) const override;

private:
  float sideLength;
  Color color;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
