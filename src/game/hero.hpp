#ifndef SIMPLEPLATFORMER_GAME_HERO_HPP
#define SIMPLEPLATFORMER_GAME_HERO_HPP
#include <engine/actor.hpp>
class Hero : public Actor {
public:
  Hero(std::uint_fast64_t id);
  void HandleKeyDownEvent(const EventKeyDown &e) override;
};
#endif // SIMPLEPLATFORMER_GAME_HERO_HPP
