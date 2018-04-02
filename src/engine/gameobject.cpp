#include <cmath>
#include <engine/gameobject.hpp>
std::pair<float, float> GameObject::Transform::TransformPoint(
    const std::pair<float, float> &point,
    const std::pair<float, float> &dimension) const {
  // Copy point.
  std::pair<float, float> p(point);

  // Regard pivot.
  p.first -= dimension.first * pivot.first;
  p.second -= dimension.second * pivot.second;

  // Calculate the displacement considering scale.
  float d = sqrt(p.first * p.first * scale.first +
                 p.second * p.second * scale.second);
  float theta = atan(p.second / p.first) + rotation;

  // Calculate transformed position.
  p.first = d * cos(theta) + position.first;
  p.second = d * sin(theta) + position.second;

  return p;
}
