#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
#include <Box2D/Box2D.h>
#include <engine/transform.hpp>
#include <memory>
#include <vector>
class PhysicalBody {
public:
  virtual ~PhysicalBody();

  // UpdateShape method might need be called inside the constructor, but calling a virtual method inside a constructor is not
  // recommended. Therefore, make a non-virtual implementation of this function and call it inside the constructor if needed.
  virtual void UpdateShape(const Transform &transform) = 0;

  void SetPosition(const b2Vec2 &position);
  void SetRotation(float rotation);
  const b2Vec2 GetPosition() const;
  b2Vec2 GetPosition();
  const float GetRotation() const;
  float GetRotation();

protected:
  // Box2D body.
  // This should be automatically cleaned up by world.
  // Destructor should not free or delete this.
  b2Body *body;
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
