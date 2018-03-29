#ifndef SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#define SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#include <vector>
#include <memory>
#include <engine/scene.h>
#include <engine/allegro5_wrapper.h>
// Director class manages all scenes in game.
// This is a singleton class, so at any given time, there should only be one instance of Director existing.
class Director {
 public:
  // Default refresh rate.
  static const float kLoopInterval;

  // Append a new scene to scenes and return its reference.
  static Scene &AddScene(const std::string &name);

  // Start the main game loop.
  static void Start();
 private:
  // Return the reference of the singleton object.
  static Director &Get();

  // There is no public constructor for Director class in order to enforce singleton pattern.
  // Private constructor should only be called by Get() method.
  Director() = default;

  // Allegro wrapper instance for graphics management.
  Allegro5Wrapper allegro;

  // Collection of all scenes in game.
  std::vector<Scene> scenes;
};
#endif //SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
