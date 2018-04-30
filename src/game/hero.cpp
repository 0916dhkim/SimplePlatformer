#include <engine/director.hpp>
#include <engine/event/keycode.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <game/hero.hpp>
Hero::Hero(std::uint_fast64_t id) : Actor(id), move_speed(10), moving_right(false), moving_left(false) {
  SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*this, 1, b2Vec2(0.5, 0.5), Color::RED)));
  SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*this, b2Vec2(0.5, 0.5), 1)));
  AddTag("hero");
}

void Hero::HandleKeyDownEvent(const EventKeyDown &e) {
  switch (e.keycode) {
  case KeyCode::UP: {
    // Check if hero is touching ground.
    std::vector<std::weak_ptr<Actor>> actors = body->GetTouchingActors();
    for (auto actor : actors) {
      if (!actor.expired() && actor.lock()->HasTag("ground")) {
        // Jump.
        body->ApplyLinearImpulse(b2Vec2(0, 10));
        break;
      }
    }
    break;
  }
  case KeyCode::LEFT:
    moving_left = true;
    break;
  case KeyCode::RIGHT:
    moving_right = true;
    break;
  default:
    break;
  }
}

void Hero::HandleKeyUpEvent(const EventKeyUp &e) {
  switch (e.keycode) {
  case KeyCode::LEFT:
    moving_left = false;
    break;
  case KeyCode::RIGHT:
    moving_right = false;
    break;
  default:
    break;
  }
}

void Hero::Update() {
  // Make camera follow this hero.
  Director::GetCamera().transform.p = GetTransform().GetPosition();

  // Apply appropriate velocity.
  b2Vec2 original_velocity = body->GetLinearVelocity();
  if (moving_left && !moving_right) {
    if (original_velocity.x >= -move_speed) {
      body->SetLinearVelocity(b2Vec2(-move_speed, original_velocity.y));
    }
  }
  if (moving_right && !moving_left) {
    if (original_velocity.x <= move_speed) {
      body->SetLinearVelocity(b2Vec2(move_speed, original_velocity.y));
    }
  }
}
