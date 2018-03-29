#include <engine/scene.h>
std::string Scene::GetName() const { return this->name; }

Scene::Scene(const std::string &name) : name(name) {}