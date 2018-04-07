#ifndef SIMPLEPLATFORMER_ENGINE_CONVERT_H
#define SIMPLEPLATFORMER_ENGINE_CONVERT_H
#include <engine/camera.hpp>
#include <engine/transform.hpp>
namespace Convert {
b2Vec2 TransformCoordinates(const Transform &transform, const b2Vec2 &p,
                            float width, float height);

b2Vec2 LocalToWorld(const Transform &object_transform, const b2Vec2 &p);

b2Vec2 WorldToScreen(const Camera &camera, const b2Vec2 &p);
} // namespace Convert
#endif // SIMPLEPLATFORMER_ENGINE_CONVERT_H
