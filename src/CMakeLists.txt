add_executable(simpleplatformer
        engine/director.cpp
        engine/scene.cpp
        engine/allegro5_wrapper.cpp
        main.cpp
)
target_link_libraries(simpleplatformer allegro allegro_primitives)
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
