#include <engine.hpp>
#include <random>

class PresentationScene : public Scene {
public:
  void Play(Stage &stage) const override {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> c(100, 255);
    std::uniform_int_distribution<std::mt19937::result_type> x(-30, 30);
    std::uniform_int_distribution<std::mt19937::result_type> y(10, 30);

    Camera &cam = stage.GetCamera();
    cam.size = 80;

    Director::GetWorld().SetGravity(b2Vec2(0, -40));

    for (int ii = 0; ii < 200; ++ii) {
      std::shared_ptr<Actor> a = stage.AddActor<Actor>().lock();
      if (a) {
        Color randc;
        randc.r = c(rng);
        randc.g = c(rng);
        randc.b = c(rng);
        randc.a = 255;
        a->SetPosition(x(rng), y(rng));
        a->SetRenderer(std::unique_ptr<Renderer>(new TriangleRenderer(*a, 1, b2Vec2(0.5, 0.5), randc)));
        a->SetBody(std::unique_ptr<PhysicalBody>(new DynamicTriangle(*a, b2Vec2(0.5, 0.5), 1)));
      }
    }
    std::shared_ptr<Actor> line = stage.AddActor<Actor>().lock();
    line->SetPosition(0, -30);
    line->SetRenderer(std::unique_ptr<Renderer>(new LineRenderer(*line, b2Vec2(0.5, 0.5), 300, Color::WHITE)));
    line->SetBody(std::unique_ptr<PhysicalBody>(new StaticLine(*line, b2Vec2(0.5, 0.5), 300)));
  }
};

int main() {
  Director::LoadScene(PresentationScene());
  Director::Start();
  return 0;
}
