#include <array>
#include <cmath>
#include <engine/director.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/transform.hpp>
DynamicTriangle::DynamicTriangle(const Transform &transform, float sideLength) : sideLength(sideLength) {
  // Create body.
  b2BodyDef bdef;
  bdef.type = b2_dynamicBody;
  bdef.position = transform.GetPosition();
  bdef.angle = transform.GetRotation();
  body = Director::GetWorld().CreateBody(&bdef);

  // Create Fixture.
  UpdateShape(transform);
}

void DynamicTriangle::UpdateShape(const Transform &transform) {
  // Calculate the new shape.
  b2PolygonShape shape;
  float w = sideLength;
  float h = sideLength * std::sqrt(3) / 2.0f;
  std::array<b2Vec2, 3> vertices = {b2Vec2(0, 0), b2Vec2(w, 0), b2Vec2(w / 2.0f, h)};
  for (b2Vec2 &v : vertices) {
    v = transform.ToPivot(v);
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
