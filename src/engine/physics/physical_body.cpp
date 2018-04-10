#include <engine/physics/physical_body.hpp>
PhysicalBody::~PhysicalBody() {
  // Destroy the body from the world.
  body->GetWorld()->DestroyBody(body);
}

void PhysicalBody::SetPosition(const b2Vec2 &position) { body->SetTransform(position, body->GetAngle()); }

const b2Vec2 PhysicalBody::GetPosition() const { return body->GetPosition(); }

b2Vec2 PhysicalBody::GetPosition() { return body->GetPosition(); }

const float PhysicalBody::GetRotation() const { return body->GetAngle(); }

float PhysicalBody::GetRotation() { return body->GetAngle(); }

void PhysicalBody::SetRotation(float rotation) { body->SetTransform(body->GetPosition(), rotation); }
