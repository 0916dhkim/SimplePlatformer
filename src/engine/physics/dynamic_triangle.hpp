#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#include <engine/physics/physical_body.hpp>
#include <engine/transform.hpp>
class DynamicTriangle : public PhysicalBody {
public:
  DynamicTriangle(Actor &actor, const b2Vec2 &pivot, float sideLength);
  void UpdateShape() override;

private:
  float sideLength;
  b2Vec2 pivot;

  // Non-virtual implemenation of UpdateShape.
  void UpdateShapeImpl();
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
