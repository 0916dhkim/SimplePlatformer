#ifndef SIMPLEPLATFORMER_DIRECTOR_H
#define SIMPLEPLATFORMER_DIRECTOR_H
#include <vector>
#include <memory>
#include <scene.h>
// Director class manages all scenes in game.
// This is a singleton class, so at any given time, there should only be one instance of Director existing.
class Director {
 private:
  // Return the reference of the singleton object.
  static Director &Get();

  // There is no public constructor for Director class in order to enforce singleton pattern.
  // Private constructor should only be called by Get() method.
  Director() = default;

  // Collection of all scenes in game.
  std::vector<Scene> scenes;
};
#endif //SIMPLEPLATFORMER_DIRECTOR_H
