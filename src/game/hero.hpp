#ifndef SIMPLEPLATFORMER_GAME_HERO_HPP
#define SIMPLEPLATFORMER_GAME_HERO_HPP
#include <engine.hpp>
class Hero : public Actor {
public:
  Hero(std::uint_fast64_t id);
  void HandleKeyDownEvent(const EventKeyDown &e) override;
  void HandleKeyUpEvent(const EventKeyUp &e) override;
  void Update() override;

private:
  float move_speed;

  bool moving_right;
  bool moving_left;
};
#endif // SIMPLEPLATFORMER_GAME_HERO_HPP
