#ifndef SIMPLEPLATFORMER_ENGINE_ACTOR_H
#define SIMPLEPLATFORMER_ENGINE_ACTOR_H
#include <engine/gameobject.hpp>
#include <engine/renderer/renderer.hpp>
#include <memory>
class Actor {
public:
  Actor(const unsigned long &id, const GameObject &gameobject);

  // Render the game object given the transform of the camera.
  void Render(const Camera &camera) const;

private:
  unsigned long id;
  GameObject gameobject;
  std::unique_ptr<Renderer> renderer;
};
#endif // SIMPLEPLATFORMER_ENGINE_ACTOR_H
