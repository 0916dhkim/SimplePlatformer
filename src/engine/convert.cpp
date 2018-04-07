#include <cmath>
#include <engine/convert.hpp>
#include <engine/director.hpp>
namespace Convert {
b2Vec2 TransformCoordinates(const Transform &transform, const b2Vec2 &p,
                            float width, float height) {
  b2Vec2 ret;
  ret.x = (p.x - width * transform.pivot.x) * transform.scale.x;
  ret.y = (p.y - height * transform.pivot.y) * transform.scale.y;
  return ret;
}

b2Vec2 LocalToWorld(const Transform &object_transform, const b2Vec2 &p) {
  float armLength = std::sqrt(p.x * p.x + p.y * p.y);
  float armAngle;
  if (armLength == 0) {
    armAngle = 0;
  } else {
    armAngle = std::acos(p.x / armLength);
    if (p.y < 0) {
      armAngle *= -1;
    }
  }

  b2Vec2 ret;
  ret.x = object_transform.position.x +
          armLength * std::cos(armAngle + object_transform.rotation);
  ret.y = object_transform.position.y +
          armLength * std::sin(armAngle + object_transform.rotation);
  return ret;
}

b2Vec2 WorldToScreen(const Camera &camera, const b2Vec2 &p) {
  float tx = p.x - camera.transform.position.x;
  float ty = p.y - camera.transform.position.y;

  float armLength = std::sqrt(tx * tx + ty * ty);
  float armAngle;
  if (armLength == 0) {
    armAngle = 0;
  } else {
    armAngle = std::acos(p.x / armLength);
    if (p.y < 0) {
      armAngle *= -1;
    }
  }

  b2Vec2 ret;
  ret.x = armLength * std::cos(armAngle - camera.transform.rotation) *
          static_cast<float>(Director::Allegro().GetDisplayHeight()) /
          camera.size;
  ret.y = armLength * std::sin(armAngle - camera.transform.rotation) *
          static_cast<float>(Director::Allegro().GetDisplayHeight()) /
          camera.size;
  ret.y = static_cast<float>(Director::Allegro().GetDisplayHeight()) - ret.y;
  return ret;
}
} // namespace Convert
