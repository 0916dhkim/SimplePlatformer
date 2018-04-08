#include <Box2D/Box2D.h>
#include <engine/convert.hpp>
#include <engine/director.hpp>
#include <engine/physics/static_line.hpp>

StaticLine::StaticLine(float length, const Transform &transform) {
  // Create body.
  b2BodyDef bdef;
  bdef.type = b2_staticBody;
  bdef.position = transform.position;
  body = Director::GetWorld().CreateBody(&bdef);

  // Define shape.
  b2EdgeShape shape;
  b2Vec2 p1(0, 0);
  b2Vec2 p2(length, 0);
  p1 = Convert::TransformCoordinates(transform, p1, length, 0);
  p2 = Convert::TransformCoordinates(transform, p2, length, 0);
  shape.Set(p1, p2);

  // Create fixture.
  body->CreateFixture(&shape, 1);
}
