#include <engine/actor.hpp>
#include <engine/renderer/triangle_renderer.hpp>
Actor::Actor(std::uint_fast64_t id) : id(id) {}

void Actor::SetBody(std::unique_ptr<PhysicalBody> &&body) {
  this->body = std::move(body);
}

void Actor::SetRenderer(std::unique_ptr<Renderer> &&renderer) {
  this->renderer = std::move(renderer);
}

Transform &Actor::GetTransform() { return transform; }

void Actor::Render(const Camera &camera) const {
  renderer->Render(transform, camera);
}

void Actor::UpdateTransform() {
  transform.position = body->GetPosition();
  transform.rotation = body->GetRotation();
}
