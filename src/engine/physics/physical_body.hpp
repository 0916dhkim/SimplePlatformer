#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
#include <Box2D/Box2D.h>
#include <memory>
#include <vector>
class PhysicalBody {
public:
  virtual ~PhysicalBody();
  b2Vec2 GetPosition();
  float GetRotation();

protected:
  // Box2D body.
  // This should be automatically cleaned up by world.
  // Destructor should not free or delete this.
  b2Body *body;
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_PHYSICAL_BODY_H
