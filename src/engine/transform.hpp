#ifndef SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#define SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#include <Box2D/Common/b2Math.h> // b2Vec2
struct Transform {
  b2Vec2 pivot = {0.5, 0.5};

  b2Vec2 position = {0, 0};

  float rotation = 0;

  b2Vec2 scale = {1, 1};
};
#endif // SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
