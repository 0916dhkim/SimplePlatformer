#include <engine/renderable/triangle_attribute.hpp>
#include <game/main_scene.hpp>
MainScene::MainScene() {
  GameObject g1;
  g1.transform.position.x = 2;
  g1.transform.position.y = 2;
  g1.transform.pivot.x = 0.5;
  g1.transform.pivot.y = 0.5;
  g1.renderable.type = Renderable::Type::TRIANGLE;
  g1.renderable.attribute.triangle.side_length = 1;
  g1.renderable.attribute.triangle.color = {255, 255, 0, 255};
  gameobjects.push_back(g1);

  GameObject g2;
  g2.transform.position.x = 0;
  g2.transform.position.y = 0;
  g2.transform.pivot.x = 0;
  g2.transform.pivot.y = 0;
  g2.renderable.type = Renderable::Type::TRIANGLE;
  g2.renderable.attribute.triangle.side_length = 2;
  g2.renderable.attribute.triangle.color = {0, 0, 255, 255};
  gameobjects.push_back(g2);

  camera.size = 10;
}
