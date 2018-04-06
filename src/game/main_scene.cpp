#include <engine/renderer/triangle_renderer.hpp>
#include <game/main_scene.hpp>
void MainScene::Play(Stage &stage) const {
  // Set camera.
  Camera &cam = stage.GetCamera();
  cam.size = 5;

  std::shared_ptr<Actor> a1 = stage.AddActor();
  if (a1 != nullptr) {
    a1->AddRenderer(new TriangleRenderer(3, {255, 255, 255, 255}));
    a1->GetTransform().pivot = {0, 0};
  }
}
