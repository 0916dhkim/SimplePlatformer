#ifndef SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#define SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#include <Box2D/Common/b2Math.h> // b2Vec2
#include <engine/camera.hpp>
// Represents transformation of actor class.
class Transform {
public:
  Transform();
  Transform(const Transform &transform);
  Transform(Transform &&transform) noexcept;
  Transform &operator=(const Transform &transform);
  Transform &operator=(Transform &&transform) noexcept;

  // Getters.
  b2Vec2 GetPosition() const;
  float GetRotation() const;
  b2Vec2 GetScale() const;

  // Setters.
  void SetPosition(const b2Vec2 &position);
  void SetPosition(float x, float y);
  void SetRotation(float rotation);
  void SetScale(const b2Vec2 &scale);
  void SetScale(float x, float y);

  // Coordinate system conversions.

  // Take one point that is in not pivoted local coordinate system.
  // Return the world coordinates of the point.
  b2Vec2 ToWorld(const b2Vec2 &orig) const;
  // Take one point that is not pivoted local coordinate system.
  // and a camera instance.
  // Return the screen coordinates of the point.
  b2Vec2 ToScreen(const b2Vec2 &orig, const Camera &camera) const;

private:
  // Box2D math transform.
  // Holds position and rotation info.
  b2Transform b2transform;
  b2Vec2 scale;
};
#endif // SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
