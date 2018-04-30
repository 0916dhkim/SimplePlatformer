#include <engine/color.hpp>
#include <engine/director.hpp>
#include <engine/physics/dynamic_triangle.hpp>
#include <engine/physics/static_line.hpp>
#include <engine/renderer/line_renderer.hpp>
#include <engine/renderer/triangle_renderer.hpp>
#include <game/hero.hpp>
#include <game/main_scene.hpp>
void MainScene::Play(Stage &stage) const {
  // Set camera.
  Camera &cam = stage.GetCamera();
  cam.size = 15;

  // Set gravity.
  Director::GetWorld().SetGravity(b2Vec2(0, -40));

  std::shared_ptr<Actor> hero = stage.AddActor<Hero>();
  if (hero != nullptr) {
    hero->SetPosition(0, 8);
  }

  std::shared_ptr<Actor> a1 = stage.AddActor<Actor>();
  if (a1 != nullptr) {
    a1->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*(a1.get()), 1, b2Vec2(0.5, 0.5), Color::WHITE)));
    a1->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*(a1.get()), b2Vec2(0.5, 0.5), 1)));
    a1->SetPosition(3, 8);
  }

  std::shared_ptr<Actor> a2 = stage.AddActor<Actor>();
  if (a2 != nullptr) {
    a2->SetPosition(0, 13);
    a2->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*(a2.get()), 5, b2Vec2(0, 0.5), Color::GREEN)));
    a2->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*(a2.get()), b2Vec2(0, 0.5), 5)));
  }

  std::shared_ptr<Actor> a3 = stage.AddActor<Actor>();
  if (a3 != nullptr) {
    a3->SetRotation(0.1);
    a3->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(*(a3.get()), b2Vec2(0, 0), 20, Color::RED)));
    a3->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(*(a3.get()), b2Vec2(0, 0), 20)));
    a3->SetPosition(-7, -7);
    a3->AddTag("ground");
  }

  std::shared_ptr<Actor> a4 = stage.AddActor<Actor>();
  if (a4 != nullptr) {
    a4->SetRotation(-0.1);
    a4->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(*(a4.get()), b2Vec2(1, 0), 20, Color::BLUE)));
    a4->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(*(a4.get()), b2Vec2(1, 0), 20)));
    a4->SetPosition(-7, -7);
    a4->AddTag("ground");
  }
}
