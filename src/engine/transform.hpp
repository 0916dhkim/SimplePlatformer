#ifndef SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#define SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#include <utility>
struct Vector2 {
  float x;
  float y;
};

struct Transform {
  Vector2 pivot = {0.5, 0.5};

  Vector2 position = {0, 0};

  float rotation = 0;

  Vector2 scale = {1, 1};
};
#endif // SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
