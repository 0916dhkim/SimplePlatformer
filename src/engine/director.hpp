#ifndef SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#define SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
#include <chrono>
#include <engine/allegro5_wrapper.hpp>
#include <engine/scene.hpp>
#include <engine/stage.hpp>
#include <map>
#include <memory>
// Director class manages all scenes in game.
// This is a singleton class, so at any given time, there should only be one
// instance of Director existing.
class Director : b2ContactListener {
public:
  // Get Allegro Wrapper.
  static Allegro5Wrapper &Allegro();

  // Get Box2D world.
  static b2World &GetWorld();

  // Load a scene.
  static void LoadScene(const Scene &scene);

  // Start the main game loop.
  static void Start();

  // b2ContactListener methods override.
  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;

private:
  // Default refresh rate.
  static const double kLoopInterval;
  // Iteration count for velocity.
  static const int kPhysicsVelocityIterations;
  // Iteration count for position.
  static const int kPhysicsPositionIterations;

  // Return the reference of the singleton object.
  static Director &Get();

  // There is no public constructor for Director class in order to enforce
  // singleton pattern. Private constructor should only be called by Get()
  // method.
  Director();

  // Allegro wrapper instance for graphics management.
  Allegro5Wrapper allegro;

  // Font used for displaying debugging information.
  std::shared_ptr<ALLEGRO_FONT> debug_font;

  // Time interval between the latest two frames.
  // Measured in seconds.
  std::chrono::duration<double> dt;

  // Timestamp of the lastest frame.
  std::chrono::time_point<std::chrono::steady_clock> timestamp;

  // Box2D world instance
  b2World world;

  // The scene that is loaded in game.
  Stage stage;

  void SimulatePhysics();

  void Render();
};
#endif // SIMPLEPLATFORMER_ENGINE_DIRECTOR_H
