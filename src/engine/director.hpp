#ifndef SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#define SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#include <engine/allegro5_wrapper.hpp>
#include <engine/scene.hpp>
#include <map>
#include <memory>
// Director class manages all scenes in game.
// This is a singleton class, so at any given time, there should only be one
// instance of Director existing.
class Director {
public:
  // Default refresh rate.
  static const float kLoopInterval;

  // Append a new scene to scenes and return its reference.
  static std::pair<std::map<std::string, Scene>::iterator, bool>
  AddScene(const std::string &name);

  // Get Allegro Wrapper.
  static Allegro5Wrapper &Allegro();

  // Start the main game loop.
  static void Start();

private:
  // Return the reference of the singleton object.
  static Director &Get();

  // There is no public constructor for Director class in order to enforce
  // singleton pattern. Private constructor should only be called by Get()
  // method.
  Director() = default;

  // Allegro wrapper instance for graphics management.
  Allegro5Wrapper allegro;

  // Collection of all scenes in game.
  std::map<std::string, Scene> scenes;
};
#endif // SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
