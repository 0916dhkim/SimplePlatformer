#ifndef SIMPLEPLATFORMER_ENGINE_RENDERER_BITMAP_RENDERER
#define SIMPLEPLATFORMER_ENGINE_RENDERER_BITMAP_RENDERER
#include <engine/allegro5_wrapper.hpp>
#include <engine/renderer/renderer.hpp>
#include <string>
class BitmapRenderer : public Renderer {
public:
  BitmapRenderer(Actor &actor, const b2Vec2 &pivot, const std::string &bitmap_name, float width, float height);
  void Render(const Camera &camera) const override;

private:
  std::shared_ptr<ALLEGRO_BITMAP> bitmap;
  float width;
  float height;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERER_BITMAP_RENDERER
