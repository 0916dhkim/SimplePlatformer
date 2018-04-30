#include <engine/director.hpp>
#include <engine/physics/physical_body.hpp>
PhysicalBody::PhysicalBody(Actor &actor) : actor(actor) {}

PhysicalBody::~PhysicalBody() {
  // Destroy the body from the world.
  body->GetWorld()->DestroyBody(body);
}

void PhysicalBody::SetPosition(const b2Vec2 &position) {
  body->SetAwake(true);
  body->SetTransform(position, body->GetAngle());
}

const b2Vec2 PhysicalBody::GetPosition() const { return body->GetPosition(); }

b2Vec2 PhysicalBody::GetPosition() { return body->GetPosition(); }

const float PhysicalBody::GetRotation() const { return body->GetAngle(); }

float PhysicalBody::GetRotation() { return body->GetAngle(); }

void PhysicalBody::SetRotation(float rotation) {
  body->SetAwake(true);
  body->SetTransform(body->GetPosition(), rotation);
}

std::vector<std::weak_ptr<Actor>> PhysicalBody::GetTouchingActors() {
  std::vector<std::weak_ptr<Actor>> ret;
  b2ContactEdge *contact = body->GetContactList();
  while (contact) {
    std::weak_ptr<Actor> actor = Director::GetActor(GetUserData(contact->other));
    if (!actor.expired()) {
      ret.push_back(actor);
    }
    contact = contact->next;
  }

  return ret;
  ;
}

void PhysicalBody::ApplyLinearImpulse(const b2Vec2 &impulse) { body->ApplyLinearImpulseToCenter(impulse, true); }

b2Vec2 PhysicalBody::GetLinearVelocity() const { return body->GetLinearVelocity(); }

void PhysicalBody::SetLinearVelocity(const b2Vec2 &velocity) { body->SetLinearVelocity(velocity); }

void *PhysicalBody::MakeUserData() const { return const_cast<std::uint_fast64_t *>(&(actor.id)); }

const std::uint_fast64_t PhysicalBody::GetUserData(const b2Body *body) {
  return *(static_cast<std::uint_fast64_t *>(body->GetUserData()));
}
