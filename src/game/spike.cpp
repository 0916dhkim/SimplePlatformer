#include <game/spike.hpp>
#include <iostream>
Spike::Spike(std::uint_fast64_t id) : Actor(id) {
  SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*this, 2, b2Vec2(0.5, 0), Color::WHITE)));
  SetBody(std::unique_ptr<PhysicalBody>(new StaticTriangle(*this, b2Vec2(0.5, 0), 2)));
}

void Spike::HandleBeginContactEvent(const EventBeginContact &e) {
  std::shared_ptr<Actor> other = Director::GetActor(e.other_id).lock();
  if (other && other->HasTag("hero")) {
    std::clog << "spike!" << std::endl;
  }
}
