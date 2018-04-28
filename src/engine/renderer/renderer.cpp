#include <engine/renderer/renderer.hpp>
Renderer::Renderer(Transform &transform, const b2Vec2 &pivot) : pivot(pivot), transform(transform) {}

Transform &Renderer::GetTransform() { return transform; }

const Transform &Renderer::GetTransform() const { return transform; }
