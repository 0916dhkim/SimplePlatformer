#ifndef SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
#define SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
#include <engine/renderable/renderable.hpp>
#include <engine/transform.hpp>
#include <memory>
#include <utility>
struct GameObject {
  Transform transform;
  Renderable renderable;
};
#endif // SIMPLEPLATFORMER_ENGINE_GAMEOBJECT_H
