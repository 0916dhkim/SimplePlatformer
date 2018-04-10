#ifndef SIMPLEPLATFORMER_ENGINE_CAMERA_H
#define SIMPLEPLATFORMER_ENGINE_CAMERA_H
#include <Box2D/Common/b2Math.h>
struct Camera {
  b2Transform transform;
  float size;
};
#endif // SIMPLEPLATFORMER_ENGINE_CAMERA_H
