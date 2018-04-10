#include <engine/director.hpp>
#include <engine/transform.hpp>
#include <utility>
Transform::Transform(const b2Vec2 &size) : size(size) {
  b2transform.Set(b2Vec2(0, 0), 0);
  scale.Set(1, 1);
  pivot.Set(0, 0);
}

Transform::Transform(const Transform &transform) = default;

Transform::Transform(Transform &&transform) = default;

Transform &Transform::operator=(const Transform &transform) = default;

Transform &Transform::operator=(Transform &&transform) = default;

b2Vec2 Transform::GetPivot() const { return pivot; }

b2Vec2 Transform::GetPosition() const { return b2transform.p; }

float Transform::GetRotation() const { return b2transform.q.GetAngle(); }

b2Vec2 Transform::GetScale() const { return scale; }

b2Vec2 Transform::GetSize() const { return size; }

void Transform::SetPivot(const b2Vec2 &pivot) { this->pivot = pivot; }

void Transform::SetPivot(float x, float y) { this->pivot.Set(x, y); }

void Transform::SetPosition(const b2Vec2 &position) { this->b2transform.p = position; }

void Transform::SetPosition(float x, float y) { this->b2transform.p.Set(x, y); }

void Transform::SetRotation(float rotation) { this->b2transform.q.Set(rotation); }

void Transform::SetScale(const b2Vec2 &scale) { this->scale = scale; }

void Transform::SetScale(float x, float y) { this->scale.Set(x, y); }

b2Vec2 Transform::ToScreen(const b2Vec2 &orig, const Camera &camera) const {
  b2Vec2 worldP = ToWorld(orig);
  b2Vec3 v3(worldP.x, worldP.y, 1);

  float screenWidth = Director::Allegro().GetDisplayWidth();
  float screenHeight = Director::Allegro().GetDisplayHeight();
  float scale = screenHeight / camera.size;

  b2Mat33 scaleMat(b2Vec3(scale, 0, 0), // x column
                   b2Vec3(0, scale, 0), // y column
                   b2Vec3(0, 0, 1));    // z column

  b2Mat33 translateMat(b2Vec3(1, 0, 0),                                          // x column
                       b2Vec3(0, 1, 0),                                          // y column
                       b2Vec3(-camera.transform.p.x, -camera.transform.p.y, 1)); // z column

  b2Mat33 pivotMat(b2Vec3(1, 0, 0),                                     // x column
                   b2Vec3(0, 1, 0),                                     // y column
                   b2Vec3(screenWidth / 2.0f, screenHeight / 2.0f, 1)); // z column

  float theta = -camera.transform.q.GetAngle();
  b2Mat33 rotationMat(b2Vec3(std::cos(theta), std::sin(theta), 0),  // x column
                      b2Vec3(-std::sin(theta), std::cos(theta), 0), // y column
                      b2Vec3(0, 0, 1));                             // z column

  b2Mat33 flipMat(b2Vec3(1, 0, 0), b2Vec3(0, -1, 0), b2Vec3(0, screenHeight, 1));

  b2Vec3 ret = b2Mul(flipMat,                              // ^ Flip y axis on screen.
                     b2Mul(pivotMat,                       // | Center to screen.
                           b2Mul(rotationMat,              // | Rotate camera.
                                 b2Mul(scaleMat,           // | Scale world to screen.
                                       b2Mul(translateMat, // | Move origin to bottom left corner.
                                             v3)))));      // * Convert to world coordinates.

  return b2Vec2(ret.x, ret.y);
}

b2Vec2 Transform::ToWorld(const b2Vec2 &orig) const { return b2Mul(b2transform, ToPivot(orig)); }

b2Vec2 Transform::ToPivot(const b2Vec2 &orig) const {
  // Convert to 3D vector.
  b2Vec3 v3(orig.x, orig.y, 1);
  b2Mat33 pivotMat(b2Vec3(1, 0, 0), b2Vec3(0, 1, 0), b2Vec3(-pivot.x * size.x, -pivot.y * size.y, 1));
  b2Mat33 scaleMat(b2Vec3(scale.x, 0, 0), b2Vec3(0, scale.y, 0), b2Vec3(0, 0, 1));

  b2Vec3 ret = b2Mul(scaleMat, b2Mul(pivotMat, v3));
  return b2Vec2(ret.x, ret.y);
}
