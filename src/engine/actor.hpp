#ifndef SIMPLEPLATFORMER_ENGINE_ACTOR_H
#define SIMPLEPLATFORMER_ENGINE_ACTOR_H
#include <cstdint>
#include <engine/physics/physical_body.hpp>
#include <engine/renderer/renderer.hpp>
#include <engine/transform.hpp>
#include <memory>
class Actor {
public:
  Actor(std::uint_fast64_t id);

  // Replace actor's current body with the given one.
  void SetBody(std::unique_ptr<PhysicalBody> &&body);

  // Replace actor's current renderer with the given one.
  void SetRenderer(std::unique_ptr<Renderer> &&renderer);

  Transform &GetTransform();

  // Render the game object given the transform of the camera.
  void Render(const Camera &camera) const;

  // Update transform with physical body position & angle.
  void UpdateTransform();

protected:
  std::uint_fast64_t id;
  std::unique_ptr<PhysicalBody> body;
  Transform transform;
  std::unique_ptr<Renderer> renderer;
};
#endif // SIMPLEPLATFORMER_ENGINE_ACTOR_H
