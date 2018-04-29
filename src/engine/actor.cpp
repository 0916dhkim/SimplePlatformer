#include <engine/actor.hpp>
#include <engine/renderer/triangle_renderer.hpp>
Actor::Actor(std::uint_fast64_t id) : id(id) {}

void Actor::SetBody(std::unique_ptr<PhysicalBody> &&physical_body) { this->body = std::move(physical_body); }

void Actor::SetRenderer(std::unique_ptr<Renderer> &&renderer) { this->renderer = std::move(renderer); }

void Actor::SetPosition(const b2Vec2 &position) {
  transform.SetPosition(position);
  if (body != nullptr) {
    body->SetPosition(position);
  }
}

void Actor::SetPosition(float x, float y) {
  transform.SetPosition(x, y);
  if (body != nullptr) {
    body->SetPosition(b2Vec2(x, y));
  }
}

void Actor::SetRotation(float rotation) {
  transform.SetRotation(rotation);
  if (body != nullptr) {
    body->SetRotation(rotation);
  }
}

Transform &Actor::GetTransform() { return transform; }

void Actor::Render(const Camera &camera) const {
  if (renderer != nullptr) {
    renderer->Render(camera);
  }
}

void Actor::UpdateActorTransform() {
  if (body != nullptr) {
    transform.SetPosition(body->GetPosition());
    transform.SetRotation(body->GetRotation());
  }
}
