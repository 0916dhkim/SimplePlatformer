#ifndef SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#define SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#include <engine/color.hpp>
#include <memory>
extern "C" {
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
}
enum struct Alignment { ALIGN_LEFT = ALLEGRO_ALIGN_LEFT, ALIGN_RIGHT = ALLEGRO_ALIGN_RIGHT, ALIGN_CENTER = ALLEGRO_ALIGN_CENTER };

class Allegro5Wrapper {
public:
  Allegro5Wrapper();
  ~Allegro5Wrapper();

  // Wrapper for al_clear_to_color
  void ClearToColor(Color color);

  // Wrapper for al_draw_filled_triangle
  void DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color);

  // Wrapper for al_draw_line
  void DrawLine(float x1, float y1, float x2, float y2, Color color, float thickness);

  // Wrapper for al_draw_text
  void DrawText(const std::shared_ptr<ALLEGRO_FONT> &font, Color color, float x, float y, Alignment align,
                const std::string &text);

  // Wrapper for al_flip_display
  void FlipDisplay();

  // Wrapper for al_get_display_height
  int GetDisplayHeight();

  // Wrapper for al_get_display_width
  int GetDisplayWidth();

  // Wrapper for al_load_font
  std::shared_ptr<ALLEGRO_FONT> LoadFont(const std::string &font_name, int size);

  // Wrapper for al_wait_for_event_timed
  std::unique_ptr<ALLEGRO_EVENT, decltype(free) *> WaitForEventTimed(float secs);

private:
  const int kDefaultWidth = 960;
  const int kDefaultHeight = 720;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;

  // Return font path
  std::string GetFontPath(const std::string &font_name);
};
#endif // SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
