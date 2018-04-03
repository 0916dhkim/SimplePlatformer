#ifndef SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#define SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
#include <utility>
struct Transform {
  struct Pivot {
    float x = 0.5;
    float y = 0.5;
  } pivot;

  struct Position {
    float x = 0;
    float y = 0;
  } position;

  float rotation = 0;

  struct Scale {
    float x = 1;
    float y = 1;
  } scale;
};
#endif // SIMPLEPLATFORMER_ENGINE_TRANSFORM_H
