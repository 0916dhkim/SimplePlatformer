#ifndef SIMPLEPLATFORMER_ENGINE_STAGE_H
#define SIMPLEPLATFORMER_ENGINE_STAGE_H
#include <engine/actor.hpp>
#include <engine/gameinfo.hpp>
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
  std::shared_ptr<Actor> AddActor();

  Camera &GetCamera();

  // Return the begin and the end iterator of actors.
  std::pair<std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator,
            std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator>
  GetActors();

  // Create new gameinfo object and discard the old one.
  std::shared_ptr<GameInfo> CreateGameInfo();
  std::shared_ptr<GameInfo> GetGameInfo();

private:
  // All actors
  std::map<std::uint_fast64_t, std::shared_ptr<Actor>> actors;

  // Game information
  std::shared_ptr<GameInfo> gameinfo;

  // Camera
  Camera camera;

  // Clear the stage.
  void Clear();
};
#endif // SIMPLEPLATFORMER_ENGINE_STAGE_H
