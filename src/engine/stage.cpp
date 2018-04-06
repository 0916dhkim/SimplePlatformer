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

void Stage::Render() const {
  for (auto a : actors) {
    a.second->Render(camera);
  }
}
