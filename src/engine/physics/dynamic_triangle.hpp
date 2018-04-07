#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
#include <engine/physics/physical_body.hpp>
#include <engine/transform.hpp>
class DynamicTriangle : public PhysicalBody {
public:
  DynamicTriangle(float sideLength, const Transform &transform);
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_DYNAMIC_TRIANGLE_H
