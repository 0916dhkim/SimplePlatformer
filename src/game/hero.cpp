#include <engine/physics/dynamic_triangle.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <game/hero.hpp>
#include <iostream>
Hero::Hero(std::uint_fast64_t id) : Actor(id) {
  SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*this, 1, b2Vec2(0.5, 0.5), Color::RED)));
  SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*this, b2Vec2(0.5, 0.5), 1)));
}

void Hero::HandleKeyDownEvent(const EventKeyDown &e) { SetPosition(0, 8); }