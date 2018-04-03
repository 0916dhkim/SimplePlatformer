#ifndef SIMPLEPLATFORMER_ENGINE_STAGE_H
#define SIMPLEPLATFORMER_ENGINE_STAGE_H
#include <engine/actor.hpp>
#include <engine/scene.hpp>
#include <map>
#include <memory>
class Stage {
public:
  Stage() = default;

  // Delte copy and move constructor.
  // Stages are not supposed to be copied or moved.
  Stage(const Stage &) = delete;
  Stage(Stage &&) = delete;

  void LoadScene(const Scene &scene);
  void Render() const;

private:
  // All actors
  std::map<unsigned long, std::shared_ptr<Actor>> actors;

  // Camera
  Camera camera;

  // Create an actor from game object and put it on the stage.
  // Return id of the created actor.
  unsigned long AddGameObject(const GameObject &gameobject);

  // Clear the stage.
  void Clear();
};
#endif // SIMPLEPLATFORMER_ENGINE_STAGE_H
