#ifndef SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#define SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
#include <engine/color.hpp>
#include <memory>
extern "C" {
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
}
class Allegro5Wrapper {
public:
  Allegro5Wrapper();
  ~Allegro5Wrapper();

  // Wrapper for al_draw_filled_triangle
  void DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3,
                          float y3, Color color);

  // Wrapper for al_flip_display
  void FlipDisplay();

  // Wrapper for al_wait_for_event_timed
  std::unique_ptr<ALLEGRO_EVENT, decltype(free) *>
  WaitForEventTimed(float secs);

private:
  const int kDefaultWidth = 960;
  const int kDefaultHeight = 720;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;
};
#endif // SIMPLEPLATFORMER_ENGINE_ALLEGRO5_WRAPPER_H
