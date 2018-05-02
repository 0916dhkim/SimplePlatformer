#include <engine/director.hpp>
#include <engine/renderer/bitmap_renderer.hpp>
BitmapRenderer::BitmapRenderer(Actor &actor, const b2Vec2 &pivot, const std::string &bitmap_name, float width, float height)
    : Renderer(actor, pivot), bitmap(Director::Allegro().LoadBitmap(bitmap_name)), width(width), height(height) {}

void BitmapRenderer::Render(const Camera &camera) const {
  int bw = Director::Allegro().GetBitmapWidth(bitmap);
  int bh = Director::Allegro().GetBitmapHeight(bitmap);
  b2Vec2 c(bw * pivot.x, bh * pivot.y);
  b2Vec2 d = actor.GetTransform().ToScreen(b2Vec2(0, 0), camera);

  b2Vec2 scale =
      static_cast<float>(Director::Allegro().GetDisplayHeight()) / Director::GetCamera().size * actor.GetTransform().GetScale();
  scale.x *= width / static_cast<float>(bw);
  scale.y *= height / static_cast<float>(bh);
  float angle = actor.GetTransform().GetRotation() - Director::GetCamera().transform.q.GetAngle();

  Director::Allegro().DrawBitmap(bitmap, c.x, c.y, d.x, d.y, scale.x, scale.y, angle);
}
