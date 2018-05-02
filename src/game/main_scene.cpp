#include <game/hero.hpp>
#include <game/main_scene.hpp>
#include <game/spike.hpp>
void MainScene::Play(Stage &stage) const {
  // Set camera.
  Camera &cam = stage.GetCamera();
  cam.size = 12;

  // Set gravity.
  Director::GetWorld().SetGravity(b2Vec2(0, -40));

  std::shared_ptr<Actor> hero = stage.AddActor<Hero>().lock();
  if (hero != nullptr) {
    hero->SetPosition(0, 8);
  }

  std::shared_ptr<Actor> a2 = stage.AddActor<Actor>().lock();
  if (a2 != nullptr) {
    a2->SetPosition(0, 13);
    a2->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*(a2.get()), 5, b2Vec2(0, 0.5), Color::GREEN)));
    a2->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*(a2.get()), b2Vec2(0, 0.5), 5)));
  }

  std::shared_ptr<Actor> a3 = stage.AddActor<Actor>().lock();
  if (a3 != nullptr) {
    a3->SetRotation(0.1);
    a3->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(*(a3.get()), b2Vec2(0, 0), 20, Color::RED)));
    a3->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(*(a3.get()), b2Vec2(0, 0), 20)));
    a3->SetPosition(-7, -7);
    a3->AddTag("ground");
  }

  std::shared_ptr<Actor> a4 = stage.AddActor<Actor>().lock();
  if (a4 != nullptr) {
    a4->SetRotation(-0.1);
    a4->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(*(a4.get()), b2Vec2(1, 0), 20, Color::BLUE)));
    a4->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(*(a4.get()), b2Vec2(1, 0), 20)));
    a4->SetPosition(-7, -7);
    a4->AddTag("ground");
  }

  std::shared_ptr<Actor> spike1 = stage.AddActor<Spike>().lock();
  if (spike1) {
    spike1->SetPosition(-11, -6);
  }
}
