#include <engine/actor.hpp>
#include <engine/renderable/renderable.hpp>
#include <engine/renderer/triangle_renderer.hpp>
Actor::Actor(const unsigned long &id, const GameObject &gameobject)
    : id(id), gameobject(gameobject) {
  switch(gameobject.renderable.type) {
    case Renderable::Type::TRIANGLE:
      renderer.reset(new TriangleRenderer(gameobject));
      break;
  }
}

void Actor::Render(const Camera &camera) const {
  renderer->Render(gameobject.transform, camera);
}

