#include <engine/stage.hpp>
std::uint_fast64_t Stage::next_id = 1;

void Stage::Clear() {
  // Remove actors.
  actors.clear();
}

Camera &Stage::GetCamera() { return camera; }

std::vector<std::weak_ptr<Actor>> Stage::GetActors() {
  std::vector<std::weak_ptr<Actor>> ret(actors.size());
  int ii;
  std::map<std::uint_fast64_t, std::shared_ptr<Actor>>::iterator it;
  for (ii = 0, it = actors.begin(); it != actors.end(); ++ii, ++it) {
    ret[ii] = it->second;
  }
  return ret;
}

std::weak_ptr<Actor> Stage::GetActor(std::uint_fast64_t id) {
  auto a = actors.find(id);
  if (a == actors.end()) {
    return std::weak_ptr<Actor>();
  }
  return a->second;
}

std::shared_ptr<GameInfo> Stage::CreateGameInfo() {
  gameinfo.reset(new GameInfo());
  return gameinfo;
}

std::shared_ptr<GameInfo> Stage::GetGameInfo() { return gameinfo; }
