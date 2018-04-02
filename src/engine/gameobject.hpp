#ifndef SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
#define SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
class GameObject {
 public:
  struct Transform {
    struct Position {
      float x = 0;  // x coordinate
      float y = 0;  // y coordinate
    } position;
    float rotation = 0;  // rotation in radians
  } transform;
};
#endif  // SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
