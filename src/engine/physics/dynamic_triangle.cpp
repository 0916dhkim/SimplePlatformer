#include <array>
#include <cmath>
#include <engine/director.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/transform.hpp>
DynamicTriangle::DynamicTriangle(Actor &actor, const b2Vec2 &pivot, float sideLength)
    : PhysicalBody(actor), sideLength(sideLength), pivot(pivot) {
  // Create body.
  b2BodyDef bdef;
  bdef.type = b2_dynamicBody;
  bdef.position = actor.GetTransform().GetPosition();
  bdef.angle = actor.GetTransform().GetRotation();
  body = Director::GetWorld().CreateBody(&bdef);

  // Create Fixture.
  UpdateShapeImpl();
}

void DynamicTriangle::UpdateShape() { return UpdateShapeImpl(); }

void DynamicTriangle::UpdateShapeImpl() {
  // Calculate the new shape.
  b2PolygonShape shape;
  float w = sideLength;
  float h = sideLength * std::sqrt(3) / 2.0f;
  std::array<b2Vec2, 3> vertices = {b2Vec2(0, 0), b2Vec2(w, 0), b2Vec2(w / 2.0f, h)};
  for (b2Vec2 &v : vertices) {
    // Apply pivot.
    v.x -= w * pivot.x;
    v.y -= h * pivot.y;
  }
  shape.Set(vertices.data(), vertices.size());

  // Destroy all fixtures.
  b2Fixture *fixture = body->GetFixtureList();
  while (fixture != nullptr) {
    body->DestroyFixture(fixture);
    fixture = body->GetFixtureList();
  }

  // Attach the new fixture.
  body->CreateFixture(&shape, 1);
}
