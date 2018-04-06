#ifndef SIMPLEPLATFORMER_ENGINE_ACTOR_H
#define SIMPLEPLATFORMER_ENGINE_ACTOR_H
#include <cstdint>
#include <engine/renderer/renderer.hpp>
#include <engine/transform.hpp>
#include <memory>
class Actor {
public:
  Actor(std::uint_fast64_t id);

  // Replace actor's current renderer with the given one.
  void AddRenderer(std::unique_ptr<Renderer> &&renderer);

  Transform &GetTransform();

  // Render the game object given the transform of the camera.
  void Render(const Camera &camera) const;

private:
  std::uint_fast64_t id;
  Transform transform;
  std::unique_ptr<Renderer> renderer;
};
#endif // SIMPLEPLATFORMER_ENGINE_ACTOR_H
