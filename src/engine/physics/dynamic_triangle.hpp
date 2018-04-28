#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#include <engine/physics/physical_body.hpp>
#include <engine/transform.hpp>
class DynamicTriangle : public PhysicalBody {
public:
  DynamicTriangle(const Transform &transform, const b2Vec2 &pivot, float sideLength);
  void UpdateShape(const Transform &transform) override;

private:
  float sideLength;
  b2Vec2 pivot;

  // Non-virtual implemenation of UpdateShape.
  void UpdateShapeImpl(const Transform &transform);
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
