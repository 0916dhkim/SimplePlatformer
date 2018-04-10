#include <engine/renderer/renderer.hpp>
Renderer::Renderer(Transform &transform) : transform(transform) {}

Transform &Renderer::GetTransform() { return transform; }

const Transform &Renderer::GetTransform() const { return transform; }
