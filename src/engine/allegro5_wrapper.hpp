#ifndef SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#define SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#include <engine/alignment.hpp>
#include <engine/color.hpp>
#include <memory>
extern "C" {
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
}

class Allegro5Wrapper {
public:
  Allegro5Wrapper();
  ~Allegro5Wrapper();

  // Wrapper for al_clear_to_color
  void ClearToColor(Color color);

  // Wrapper for al_draw_scaled_rotated_bitmap
  void DrawBitmap(const std::shared_ptr<ALLEGRO_BITMAP> &bitmap, float cx, float cy, float dx, float dy, float xscale,
                  float yscale, float angle);

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

  // Wrapper for al_get_bitmap_width
  int GetBitmapWidth(std::shared_ptr<ALLEGRO_BITMAP> bitmap);

  // Wrapper for al_get_bitmap_height
  int GetBitmapHeight(std::shared_ptr<ALLEGRO_BITMAP> bitmap);

  // Wrapper for al_load_bitmap
  std::shared_ptr<ALLEGRO_BITMAP> LoadBitmap(const std::string &bitmap_name);

  // Wrapper for al_load_font
  std::shared_ptr<ALLEGRO_FONT> LoadFont(const std::string &font_name, int size);

  // Wrapper for al_wait_for_event_timed
  std::unique_ptr<ALLEGRO_EVENT, decltype(free) *> WaitForEventTimed(float secs);

private:
  const int kDefaultWidth = 960;
  const int kDefaultHeight = 720;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;

  // Return bitmap path
  std::string GetBitmapPath(const std::string &bitmap_name);

  // Return font path
  std::string GetFontPath(const std::string &font_name);
};
#endif // SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
