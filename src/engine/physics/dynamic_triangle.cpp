#include <array>
#include <cmath>
#include <engine/convert.hpp>
#include <engine/director.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/transform.hpp>

DynamicTriangle::DynamicTriangle(float sideLength, const Transform &transform) {
  // Create body.
  b2BodyDef bdef;
  bdef.type = b2_dynamicBody;
  bdef.position = transform.position;
  body = Director::GetWorld().CreateBody(&bdef);

  // Define shape.
  b2PolygonShape shape;
  float w = sideLength;
  float h = sideLength * std::sqrt(3) / 2.0f;
  std::array<b2Vec2, 3> vertices;
  vertices[0].Set(0, 0);
  vertices[1].Set(w / 2.0f, h);
  vertices[2].Set(w, 0);
  for (b2Vec2 &v : vertices) {
    v = Convert::TransformCoordinates(transform, v, w, h);
  }
  shape.Set(vertices.data(), vertices.size());

  // Create fixture.
  body->CreateFixture(&shape, 1);
}
