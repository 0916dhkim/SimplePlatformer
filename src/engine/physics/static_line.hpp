#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#include <engine/physics/physical_body.hpp>
class StaticLine : public PhysicalBody {
public:
  StaticLine(const Transform &transform, float length);
  void UpdateShape(const Transform &transform) override;

private:
  float length;
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
