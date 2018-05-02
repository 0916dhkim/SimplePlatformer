#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_TRIANGLE_HPP
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_TRIANGLE_HPP
#include <engine/physics/physical_body.hpp>
class StaticTriangle : public PhysicalBody {
public:
  StaticTriangle(Actor &actor, const b2Vec2 &pivot, float sideLength);
  void UpdateShape() override;

private:
  float sideLength;
  b2Vec2 pivot;

  // Implementation of UpdateShape.
  void UpdateShapeImpl();
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_TRIANGLE_HPP
