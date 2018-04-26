#include <engine/color.hpp>
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
  Director::GetWorld().SetGravity(b2Vec2(0, -9.8));

  std::shared_ptr<Actor> a1 = stage.AddActor(1, std::sqrt(3) / 2.0f);
  if (a1 != nullptr) {
    a1->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(a1->GetTransform(), 1, Color::WHITE)));
    a1->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(a1->GetTransform(), 1)));
    a1->SetPosition(3, 8);
    a1->SetPivot(0.5, 0.5);
  }

  std::shared_ptr<Actor> a2 = stage.AddActor(5, 5.0f * std::sqrt(3) / 2.0f);
  if (a2 != nullptr) {
    a2->SetPosition(0, 13);
    a2->SetPivot(0, 0.5);
    a2->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(a2->GetTransform(), 5, Color::GREEN)));
    a2->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(a2->GetTransform(), 5)));
  }

  std::shared_ptr<Actor> a3 = stage.AddActor(20, 0);
  if (a3 != nullptr) {
    a3->SetRotation(0.1);
    a3->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(a3->GetTransform(), 20, Color::RED)));
    a3->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(a3->GetTransform(), 20)));
    a3->SetPosition(-7, -7);
  }
}
