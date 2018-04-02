#ifndef SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
#define SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
#include <utility>
class GameObject {
 public:
  struct Transform {
    std::pair<float, float> pivot = {0.5, 0.5};
    std::pair<float, float> position = {0, 0};
    float rotation = 0;
    std::pair<float, float> scale = {1, 1};

    // Apply translation, rotation, and scale to the given point
    // regarding pivot.
    std::pair<float, float> TransformPoint(
        const std::pair<float, float> &point,
        const std::pair<float, float> &dimension) const;
  } transform;
};
#endif  // SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
