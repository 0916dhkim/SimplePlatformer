#ifndef SIMPLEPLATFORMER_ENGINE_GAMEINFO_HPP
#define SIMPLEPLATFORMER_ENGINE_GAMEINFO_HPP
#include <map>
#include <set>
#include <string>
class GameInfo {
public:
  // Accessors.
  int GetInt(const std::string &key) const;
  float GetFloat(const std::string &key) const;
  std::string GetString(const std::string &key) const;

  // Modifiers.
  void AddInt(const std::string &key, int value);
  void AddFloat(const std::string &key, float value);
  void AddString(const std::string &key, const std::string &value);
  void UpdateInt(const std::string &key, int value);
  void UpdateFloat(const std::string &key, float value);
  void UpdateString(const std::string &key, const std::string &value);

private:
  std::set<std::string> property_keys;
  std::map<std::string, int> int_properties;
  std::map<std::string, float> float_properties;
  std::map<std::string, std::string> string_properties;
};
#endif // SIMPLEPLATFORMER_ENGINE_GAMEINFO_HPP
