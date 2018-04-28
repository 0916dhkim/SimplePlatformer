#include <engine/stage.hpp>
std::uint_fast64_t Stage::next_id = 1;

void Stage::Clear() {
  // Remove actors.
  actors.clear();
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
