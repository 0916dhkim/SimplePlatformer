#ifndef SIMPLEPLATFORMER_ENGINE_STAGE_H
#define SIMPLEPLATFORMER_ENGINE_STAGE_H
#include <engine/actor.hpp>
#include <map>
#include <memory>
class Stage {
public:
  Stage() = default;

  // Delte copy and move constructor.
  // Stages are not supposed to be copied or moved.
  Stage(const Stage &) = delete;
  Stage(Stage &&) = delete;

  // Add an actor to the stage.
  // Return the reference to the created actor.
  std::shared_ptr<Actor> AddActor(float width, float height);

  Camera &GetCamera();

  // Return the begin and the end iterator of actors.
  std::pair<std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator,
            std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator>
  GetActors();

private:
  // All actors
  std::map<std::uint_fast64_t, std::shared_ptr<Actor>> actors;

  // Camera
  Camera camera;

  // Clear the stage.
  void Clear();
};
#endif // SIMPLEPLATFORMER_ENGINE_STAGE_H
