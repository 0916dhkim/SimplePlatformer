#include <engine/actor.hpp>
#include <engine/renderer/triangle_renderer.hpp>
Actor::Actor(std::uint_fast64_t id) : id(id) {}

void Actor::AddRenderer(Renderer *renderer) { this->renderer.reset(renderer); }

Transform &Actor::GetTransform() { return transform; }

void Actor::Render(const Camera &camera) const {
  renderer->Render(transform, camera);
}
