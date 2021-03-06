add_executable(simpleplatformer
  engine/physics/dynamic_triangle.cpp
  engine/physics/static_line.cpp
  engine/physics/static_triangle.cpp
  engine/actor.cpp
  engine/allegro5_wrapper.cpp
  engine/color.cpp
  engine/director.cpp
  engine/gameinfo.cpp
  engine/renderer/bitmap_renderer.cpp
  engine/renderer/triangle_renderer.cpp
  engine/renderer/line_renderer.cpp
  engine/renderer/renderer.cpp
  engine/physics/physical_body.cpp
  engine/stage.cpp
  engine/transform.cpp
  game/hero.cpp
  game/main_scene.cpp
  game/spike.cpp
  main.cpp
)
target_link_libraries(simpleplatformer box2d allegro allegro_font allegro_primitives allegro_ttf allegro_image)
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(simpleplatformer PRIVATE cxx_std_11)
set_target_properties(simpleplatformer PROPERTIES CXX_CLANG_TIDY "clang-tidy;-checks='*'")

add_executable(presentation
  engine/physics/pop_triangle.cpp
  engine/physics/pop_line.cpp
  engine/physics/static_triangle.cpp
  engine/actor.cpp
  engine/allegro5_wrapper.cpp
  engine/color.cpp
  engine/director.cpp
  engine/gameinfo.cpp
  engine/renderer/bitmap_renderer.cpp
  engine/renderer/triangle_renderer.cpp
  engine/renderer/line_renderer.cpp
  engine/renderer/renderer.cpp
  engine/physics/physical_body.cpp
  engine/stage.cpp
  engine/transform.cpp
  game/hero.cpp
  game/main_scene.cpp
  game/spike.cpp
  presentation.cpp
)
target_link_libraries(presentation box2d allegro allegro_font allegro_primitives allegro_ttf allegro_image)
target_include_directories(presentation PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(presentation PRIVATE cxx_std_11)
set_target_properties(presentation PROPERTIES CXX_CLANG_TIDY "clang-tidy;-checks='*'")

# Format
file(GLOB_RECURSE format_targets *.cpp *.hpp)
add_custom_target(
	clang-format
	COMMAND /usr/bin/clang-format
	-style=file
	-i
	${format_targets}
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
