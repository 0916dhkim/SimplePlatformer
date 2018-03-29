add_executable(simpleplatformer
        main.cpp
        director.cpp
        scene.cpp
        allegro5_wrapper.cpp
        )
target_link_libraries(simpleplatformer allegro)
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")