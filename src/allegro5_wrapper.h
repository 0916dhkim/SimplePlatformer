#ifndef SIMPLEPLATFORMER_ALLEGRO5_WRAPPER_H
#define SIMPLEPLATFORMER_ALLEGRO5_WRAPPER_H
#include <memory>
#include <allegro5/allegro.h>
class Allegro5Wrapper {
 public:
  Allegro5Wrapper();
  ~Allegro5Wrapper();

  // Wrapper for al_flip_display
  void FlipDisplay();

  // Wrapper for al_wait_for_event_timed
  std::unique_ptr<ALLEGRO_EVENT, decltype(free) *>WaitForEventTimed(float secs);
 private:
  const int kDefaultWidth = 960;
  const int kDefaultHeight = 720;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;
};
#endif //SIMPLEPLATFORMER_ALLEGRO5_WRAPPER_H