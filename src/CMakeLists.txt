add_executable(simpleplatformer
  engine/physics/dynamic_triangle.cpp
  engine/physics/static_line.cpp
  engine/actor.cpp
  engine/allegro5_wrapper.cpp
  engine/director.cpp
  engine/renderer/triangle_renderer.cpp
  engine/renderer/line_renderer.cpp
  engine/renderer/renderer.cpp
  engine/physics/physical_body.cpp
  engine/stage.cpp
  engine/transform.cpp
  game/main_scene.cpp
  main.cpp
)
target_link_libraries(simpleplatformer box2d allegro allegro_primitives)
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(simpleplatformer PRIVATE cxx_std_11)
