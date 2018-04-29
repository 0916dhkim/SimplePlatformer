#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#include <engine/physics/physical_body.hpp>
class StaticLine : public PhysicalBody {
public:
  StaticLine(Actor &actor, const b2Vec2 &pivot, float length);
  void UpdateShape() override;

private:
  float length;
  b2Vec2 pivot;

  // Non-virtual implementation of UpdateShape.
  void UpdateShapeImpl();
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
