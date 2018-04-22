#include <engine/allegro5_wrapper.hpp>
#include <iostream>
Allegro5Wrapper::Allegro5Wrapper() {
  al_init(); // NOLINT

  // Initialize addons.
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();

  al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_REQUIRE);
  display = al_create_display(kDefaultWidth, kDefaultHeight);
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
}

Allegro5Wrapper::~Allegro5Wrapper() {
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  // Shutdown addons.
  // This should be in reverse order of initialization.
  al_shutdown_ttf_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
}

void Allegro5Wrapper::ClearToColor(Color color) { al_clear_to_color(al_map_rgba(color.r, color.g, color.b, color.a)); }

void Allegro5Wrapper::DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color) {
  al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgba(color.r, color.g, color.b, color.a));
}

void Allegro5Wrapper::DrawLine(float x1, float y1, float x2, float y2, Color color, float thickness) {
  al_draw_line(x1, y1, x2, y2, al_map_rgba(color.r, color.g, color.b, color.a), thickness);
}

void Allegro5Wrapper::DrawText(const std::shared_ptr<ALLEGRO_FONT> &font, Color color, float x, float y, Alignment align,
                               const std::string &text) {
  al_draw_text(font.get(), al_map_rgba(color.r, color.g, color.b, color.a), x, y, static_cast<int>(align), text.data());
}

void Allegro5Wrapper::FlipDisplay() { al_flip_display(); }

int Allegro5Wrapper::GetDisplayHeight() { return al_get_display_height(display); }

int Allegro5Wrapper::GetDisplayWidth() { return al_get_display_width(display); }

std::shared_ptr<ALLEGRO_FONT> Allegro5Wrapper::LoadFont(const std::string &font_name, int size) {
  // Get font path.
  std::string font_path = GetFontPath(font_name);
  std::clog << "Loading font from " << font_path << std::endl;
  // Call allegro method.
  ALLEGRO_FONT *alfont = al_load_ttf_font(font_path.data(), size, 0);

  // Wrap it inside a shared pointer.
  std::shared_ptr<ALLEGRO_FONT> ret(alfont, al_destroy_font);
  return ret;
}

std::unique_ptr<ALLEGRO_EVENT, decltype(free) *> Allegro5Wrapper::WaitForEventTimed(float secs) {
  // Dynamically allocate an ALLEGRO_EVENT.
  auto ret = std::unique_ptr<ALLEGRO_EVENT, decltype(free) *>{new ALLEGRO_EVENT, free};

  if (al_wait_for_event_timed(event_queue, ret.get(), secs)) {
    // event_queue is not empty.
    return ret;
  }
  // event_queue is empty.
  ret.reset(nullptr);
  return ret;
}

std::string Allegro5Wrapper::GetFontPath(const std::string &font_name) {
  // Fonts are located in
  // ../res/font/
  ALLEGRO_PATH *alpath = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
  al_drop_path_tail(alpath);
  al_append_path_component(alpath, "res");
  al_append_path_component(alpath, "font");
  al_set_path_filename(alpath, font_name.data());

  return al_path_cstr(alpath, ALLEGRO_NATIVE_PATH_SEP);
}
