#ifndef SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
#define SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
#include <engine/scene.hpp>
class MainScene : public Scene {
public:
  virtual void Play(Stage &stage) const;
};
#endif // SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
