#ifndef SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#define SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
#include <engine/transform.hpp>
class StaticLine : public PhysicalBody {
public:
  StaticLine(float length, const Transform &transform);
};
#endif // SIMPLEPLATFORMER_ENGINE_PHYSICS_STATIC_LINE_H
