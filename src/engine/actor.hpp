#ifndef SIMPLEPLATFORMER_ENGINE_ACTOR_H
#define SIMPLEPLATFORMER_ENGINE_ACTOR_H
#include <cstdint>
#include <engine/event/event_contact.hpp>
#include <engine/event/event_key_down.hpp>
#include <engine/physics/physical_body.hpp>
#include <engine/renderer/renderer.hpp>
#include <engine/transform.hpp>
#include <memory>
class PhysicalBody;
class Renderer;
class Actor {
public:
  Actor(std::uint_fast64_t id);

  // Replace actor's current body with the given one.
  void SetBody(std::unique_ptr<PhysicalBody> &&physical_body);

  // Replace actor's current renderer with the given one.
  void SetRenderer(std::unique_ptr<Renderer> &&renderer);

  void SetPosition(const b2Vec2 &position);
  void SetPosition(float x, float y);
  void SetRotation(float rotation);

  Transform &GetTransform();

  // Render the game object given the transform of the camera.
  void Render(const Camera &camera) const;

  // Update actor transform with physical body transform.
  void UpdateActorTransform();

  // Update method is called evey frame.
  virtual void Update() {}

  // Virtual method for handling contact.
  virtual void HandleContactEvent(const EventContact &e) {}

  // Virtual method for handling key down event.
  virtual void HandleKeyDownEvent(const EventKeyDown &e) {}

  // ID number of this.
  const std::uint_fast64_t id;

protected:
  std::unique_ptr<PhysicalBody> body;
  Transform transform;
  std::unique_ptr<Renderer> renderer;
};
#endif // SIMPLEPLATFORMER_ENGINE_ACTOR_H
