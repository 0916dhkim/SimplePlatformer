#include <engine/actor.hpp>
#include <engine/renderer/triangle_renderer.hpp>
Actor::Actor(std::uint_fast64_t id, float width, float height) : id(id), transform(b2Vec2(width, height)) {}

void Actor::SetBody(PhysicalBody *body) { this->body = std::unique_ptr<PhysicalBody>(body); }

void Actor::SetRenderer(Renderer *renderer) { this->renderer = std::unique_ptr<Renderer>(renderer); }

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

void Actor::SetPivot(const b2Vec2 &pivot) {
  transform.SetPivot(pivot);
  UpdatePhysicalTransform();
}

void Actor::SetPivot(float x, float y) {
  transform.SetPivot(x, y);
  UpdatePhysicalTransform();
}

Transform &Actor::GetTransform() { return transform; }

void Actor::Render(const Camera &camera) const {
  if (renderer != nullptr) {
    renderer->Render(camera);
  }
}

void Actor::UpdatePhysicalTransform() {
  if (body != nullptr) {
    body->SetPosition(transform.GetPosition());
    body->SetRotation(transform.GetRotation());
    body->UpdateShape(transform);
  }
}

void Actor::UpdateActorTransform() {
  if (body != nullptr) {
    transform.SetPosition(body->GetPosition());
    transform.SetRotation(body->GetRotation());
  }
}
