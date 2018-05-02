#ifndef SIMPLEPLATFORMER_GAME_SPIKE_HPP
#define SIMPLEPLATFORMER_GAME_SPIKE_HPP
#include <engine.hpp>
class Spike : public Actor {
public:
  Spike(std::uint_fast64_t id);
  void HandleBeginContactEvent(const EventBeginContact &e) override;
};
#endif // SIMPLEPLATFORMER_GAME_SPIKE_HPP
