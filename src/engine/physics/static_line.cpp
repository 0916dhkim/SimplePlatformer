#include <engine/director.hpp>
#include <engine/physics/static_line.hpp>
StaticLine::StaticLine(const Transform &transform, const b2Vec2 &pivot, float length) : length(length), pivot(pivot) {
  // Create body.
  b2BodyDef bdef;
  bdef.type = b2_staticBody;
  bdef.position = transform.GetPosition();
  bdef.angle = transform.GetRotation();
  body = Director::GetWorld().CreateBody(&bdef);

  UpdateShapeImpl(transform);
}

void StaticLine::UpdateShape(const Transform &transform) { return UpdateShapeImpl(transform); }

void StaticLine::UpdateShapeImpl(const Transform &transform) {
  // Calculate the new shape.
  b2EdgeShape shape;
  b2Vec2 p1(0, 0), p2(length, 0);

  // Apply pivot.
  b2Vec2 pivot_point = b2Vec2(length * pivot.x, 0);
  p1 -= pivot_point;
  p2 -= pivot_point;

  shape.Set(p1, p2);

  // Remove all fixtures.
  b2Fixture *fixture = body->GetFixtureList();
  while (fixture != nullptr) {
    body->DestroyFixture(fixture);
    fixture = body->GetFixtureList();
  }

  // Attach the new fixture.
  body->CreateFixture(&shape, 1);
}
