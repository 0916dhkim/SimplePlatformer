#include <engine/allegro5_wrapper.hpp>
Allegro5Wrapper::Allegro5Wrapper() {
  al_init();

  display = al_create_display(kDefaultWidth, kDefaultHeight);
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
}

Allegro5Wrapper::~Allegro5Wrapper() {
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
}

void Allegro5Wrapper::DrawFilledTriangle(float x1, float y1, float x2, float y2,
                                         float x3, float y3,
                                         ALLEGRO_COLOR color) {
  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
}

void Allegro5Wrapper::FlipDisplay() { al_flip_display(); }

std::unique_ptr<ALLEGRO_EVENT, decltype(free) *>
Allegro5Wrapper::WaitForEventTimed(float secs) {
  // Dynamically allocate an ALLEGRO_EVENT.
  auto ret = std::unique_ptr<ALLEGRO_EVENT, decltype(free) *>{
      (ALLEGRO_EVENT *)malloc(sizeof(ALLEGRO_EVENT)), free};

  if (al_wait_for_event_timed(event_queue, ret.get(), secs)) {
    // event_queue is not empty.
    return ret;
  } else {
    // event_queue is empty.
    ret.reset(nullptr);
    return ret;
  }
}
