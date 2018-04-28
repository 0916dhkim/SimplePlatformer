#include <engine/stage.hpp>
void Stage::Clear() {
  // Remove actors.
  actors.clear();
}

std::shared_ptr<Actor> Stage::AddActor() {
  // Static variable holding the next id to be assigned.
  static std::uint_fast64_t next_id = 1;

  auto res = actors.emplace(next_id, std::make_shared<Actor>(next_id));
  if (res.second) {
    // Emplace successful.
    next_id++;
    return res.first->second;
  }
  // Emplace failed.
  return nullptr;
}

Camera &Stage::GetCamera() { return camera; }

std::pair<std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator,
          std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator>
Stage::GetActors() {
  return std::make_pair(actors.begin(), actors.end());
}

std::shared_ptr<GameInfo> Stage::CreateGameInfo() {
  gameinfo.reset(new GameInfo());
  return gameinfo;
}

std::shared_ptr<GameInfo> Stage::GetGameInfo() { return gameinfo; }
