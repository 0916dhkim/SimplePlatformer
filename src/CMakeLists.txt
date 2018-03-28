add_executable(simpleplatformer
        main.cpp
        director.cpp
        scene.cpp
        )
target_include_directories(simpleplatformer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")