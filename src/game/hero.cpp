#include <engine/director.hpp>
#include <engine/event/keycode.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <game/hero.hpp>
Hero::Hero(std::uint_fast64_t id) : Actor(id) {
  SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*this, 1, b2Vec2(0.5, 0.5), Color::RED)));
  SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*this, b2Vec2(0.5, 0.5), 1)));
  AddTag("hero");
}

void Hero::HandleKeyDownEvent(const EventKeyDown &e) {
  if (e.keycode == KeyCode::UP) {
    // Check if hero is touching ground.
    std::vector<std::weak_ptr<Actor>> actors = body->GetTouchingActors();
    for (auto actor : actors) {
      if (!actor.expired() && actor.lock()->HasTag("ground")) {
        // Jump.
        body->ApplyLinearImpulse(b2Vec2(0, 10));
        break;
      }
    }
  }
}

void Hero::Update() { Director::GetCamera().transform.p = GetTransform().GetPosition(); }
