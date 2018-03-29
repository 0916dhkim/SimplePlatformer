#include <director.h>

int main(int argc, char **argv) {
  Director::AddScene("MyScene");
  Director::Start();
  return 0;
}