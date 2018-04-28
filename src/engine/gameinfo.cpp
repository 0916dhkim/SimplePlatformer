#include <engine/gameinfo.hpp>
int GameInfo::GetInt(const std::string &key) const { return int_properties.at(key); }

float GameInfo::GetFloat(const std::string &key) const { return float_properties.at(key); }

std::string GameInfo::GetString(const std::string &key) const { return string_properties.at(key); }

void GameInfo::AddInt(const std::string &key, int value) { int_properties.insert({key, value}); }

void GameInfo::AddFloat(const std::string &key, float value) { float_properties.insert({key, value}); }

void GameInfo::AddString(const std::string &key, const std::string &value) { string_properties.insert({key, value}); }

void GameInfo::UpdateInt(const std::string &key, int value) { int_properties.at(key) = value; }

void GameInfo::UpdateFloat(const std::string &key, float value) { float_properties.at(key) = value; }

void GameInfo::UpdateString(const std::string &key, const std::string &value) { string_properties.at(key) = value; }
