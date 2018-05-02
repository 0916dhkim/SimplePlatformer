#ifndef SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
#define SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
#include <engine.hpp>
class MainScene : public Scene {
public:
  void Play(Stage &stage) const override;
};
#endif // SIMPLEPLATFORMER_GAME_MAIN_SCENE_H
