#ifndef SIMPLEPLATFORMER_ENGINE_COLOR_H
#define SIMPLEPLATFORMER_ENGINE_COLOR_H
struct Color {
  // All fields should be in range (0, 255).
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;

  // Some predefined colors.
  static const Color WHITE;
  static const Color BLACK;
  static const Color RED;
  static const Color GREEN;
  static const Color BLUE;
};
#endif // SIMPLEPLATFORMER_ENGINE_COLOR_H
