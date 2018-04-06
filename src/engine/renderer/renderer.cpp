#include <cmath>
#include <engine/director.hpp>
#include <engine/renderer/renderer.hpp>
Vector2 Renderer::VertexCoordinate(const Transform &object_transform,
                                   const Camera &camera, const Vector2 p,
                                   const float &width, const float &height) {
  Vector2 ret;
  ret.x = (p.x - width * object_transform.pivot.x) * object_transform.scale.x;
  ret.y = (p.y - height * object_transform.pivot.y) * object_transform.scale.y;

  ret = LocalToWorld(object_transform, ret);
  ret = WorldToScreen(camera, ret);

  return ret;
}

Vector2 Renderer::LocalToWorld(const Transform &object_transform,
                               const Vector2 &p) {
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

  Vector2 ret;
  ret.x = object_transform.position.x +
          armLength * std::cos(armAngle + object_transform.rotation);
  ret.y = object_transform.position.y +
          armLength * std::sin(armAngle + object_transform.rotation);
  return ret;
}

Vector2 Renderer::WorldToScreen(const Camera &camera, const Vector2 &p) {
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

  Vector2 ret;
  ret.x = armLength * std::cos(armAngle - camera.transform.rotation) *
          static_cast<float>(Director::Allegro().GetDisplayHeight()) /
          camera.size;
  ret.y = armLength * std::sin(armAngle - camera.transform.rotation) *
          static_cast<float>(Director::Allegro().GetDisplayHeight()) /
          camera.size;
  ret.y = static_cast<float>(Director::Allegro().GetDisplayHeight()) - ret.y;
  return ret;
}
