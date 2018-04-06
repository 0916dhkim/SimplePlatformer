#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
#include <engine/color.hpp>
#include <engine/renderer/renderer.hpp>
// Primitive renderer class that renders a equilateral triangle.
class TriangleRenderer : public Renderer {
public:
  TriangleRenderer(float sideLength, const Color &color);
  virtual void Render(const Transform &object_transform,
                      const Camera &camera) const;

private:
  float sideLength;
  Color color;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_TRIANGLE_RENDERER_H
