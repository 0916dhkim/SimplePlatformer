#include <engine/director.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/physics/static_line.hpp>
#include <engine/renderer/line_renderer.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <game/main_scene.hpp>
void MainScene::Play(Stage &stage) const {
  // Set camera.
  Camera &cam = stage.GetCamera();
  cam.size = 15;

  // Set gravity.
  Director::GetWorld().SetGravity(b2Vec2(0, -10));

  std::shared_ptr<Actor> a1 = stage.AddActor();
  if (a1 != nullptr) {
    a1->GetTransform().position.Set(10, 10);
    a1->SetRenderer(std::unique_ptr<Renderer>(
        new TriangleRenderer(1, {255, 255, 255, 255})));
    a1->SetBody(std::unique_ptr<PhysicalBody>(
        new DynamicTriangle(1, a1->GetTransform())));
    a1->GetTransform().pivot = {0, 0};
  }

  std::shared_ptr<Actor> a2 = stage.AddActor();
  if (a2 != nullptr) {
    a2->GetTransform().position.Set(3, 7);
    a2->SetRenderer(
        std::unique_ptr<Renderer>(new TriangleRenderer(5, {0, 255, 0, 255})));
    a2->SetBody(std::unique_ptr<PhysicalBody>(
        new DynamicTriangle(5, a2->GetTransform())));
    a2->GetTransform().pivot = {0.5f, 0};
  }

  std::shared_ptr<Actor> a3 = stage.AddActor();
  if (a3 != nullptr) {
    a3->GetTransform().position.Set(1, 1);
    a3->GetTransform().pivot.Set(0, 0);
    a3->SetRenderer(
        std::unique_ptr<Renderer>(new LineRenderer(8, {255, 0, 0, 255})));
    a3->SetBody(
        std::unique_ptr<PhysicalBody>(new StaticLine(8, a3->GetTransform())));
  }
}
