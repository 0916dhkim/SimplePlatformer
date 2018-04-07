#include <engine/physics/physical_body.hpp>

PhysicalBody::~PhysicalBody() {
  // Destroy the body from the world.
  body->GetWorld()->DestroyBody(body);
}

b2Vec2 PhysicalBody::GetPosition() { return body->GetPosition(); }

float PhysicalBody::GetRotation() { return body->GetAngle(); }
