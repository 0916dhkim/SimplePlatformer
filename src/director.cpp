#include <director.h>
Director &Director::Get() {
  static Director instance;
  return instance;
}