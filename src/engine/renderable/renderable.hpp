#ifndef SIMPLEPLATFORMER_ENGINE_RENDERABLE_RENDERABLE_H
#define SIMPLEPLATFORMER_ENGINE_RENDERABLE_RENDERABLE_H
#include <engine/renderable/triangle_attribute.hpp>
#include <memory>
#include <typeinfo>
// Tagged union
struct Renderable {
  enum struct Type { TRIANGLE } type;
  union Attribute {
    TriangleAttribute triangle;
  } attribute;
};
#endif // SIMPLEPLATFORMER_ENGINE_RENDERABLE_RENDERABLE_H
