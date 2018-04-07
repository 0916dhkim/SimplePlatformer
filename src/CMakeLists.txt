add_executable(simpleplatformer
  engine/actor.cpp
  engine/allegro5_wrapper.cpp
  engine/director.cpp
  engine/renderer/renderer.cpp
  engine/renderer/triangle_renderer.cpp
  engine/stage.cpp
  game/main_scene.cpp
  main.cpp
)
target_link_libraries(simpleplatformer box2d allegro allegro_primitives)
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(simpleplatformer PRIVATE cxx_std_11)
set_target_properties(simpleplatformer PROPERTIES CXX_CLANG_TIDY "clang-tidy;--checks=*")
