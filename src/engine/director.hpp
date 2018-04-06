#ifndef SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#define SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#include <engine/allegro5_wrapper.hpp>
#include <engine/scene.hpp>
#include <engine/stage.hpp>
#include <map>
#include <memory>
// Director class manages all scenes in game.
// This is a singleton class, so at any given time, there should only be one
// instance of Director existing.
class Director {
public:
  // Default refresh rate.
  static const float kLoopInterval;

  // Get Allegro Wrapper.
  static Allegro5Wrapper &Allegro();

  // Load a scene.
  static void LoadScene(const Scene &scene);

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

  // The scene that is loaded in game.
  Stage stage;
};
#endif // SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
