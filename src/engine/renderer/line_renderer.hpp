#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_LINE_RENDERER_H
#define SIMPLEPLATFORMER_ENGINE_RENDERER_LINE_RENDERER_H
#include <engine/color.hpp>
#include <engine/renderer/renderer.hpp>
class LineRenderer : public Renderer {
public:
  LineRenderer(Transform &transform, float length, const Color &color);
  void Render(const Camera &camera) const override;

private:
  float length;
  Color color;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_LINE_RENDERER_H
