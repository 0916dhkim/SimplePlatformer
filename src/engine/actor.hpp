#ifndef SIMPLEPLATFORMER_ENGINE_ACTOR_H
#define SIMPLEPLATFORMER_ENGINE_ACTOR_H
#include <cstdint>
#include <engine/physics/physical_body.hpp>
#include <engine/renderer/renderer.hpp>
#include <engine/transform.hpp>
#include <memory>
class Renderer;
class Actor {
public:
  Actor(std::uint_fast64_t id, float width, float height);

  // TODO Change SetBody and SetRenderer not to use raw pointers.
  // Replace actor's current body with the given one.
  void SetBody(PhysicalBody *body);

  // Replace actor's current renderer with the given one.
  void SetRenderer(Renderer *renderer);

  void SetPosition(const b2Vec2 &position);
  void SetPosition(float x, float y);
  void SetRotation(float rotation);
  void SetPivot(const b2Vec2 &pivot);
  void SetPivot(float x, float y);

  Transform &GetTransform();

  // Render the game object given the transform of the camera.
  void Render(const Camera &camera) const;

  // Update physical body transform with actor transform.
  void UpdatePhysicalTransform();
  // Update actor transform with physical body transform.
  void UpdateActorTransform();

protected:
  std::uint_fast64_t id;
  std::unique_ptr<PhysicalBody> body;
  Transform transform;
  std::unique_ptr<Renderer> renderer;
};
#endif // SIMPLEPLATFORMER_ENGINE_ACTOR_H
