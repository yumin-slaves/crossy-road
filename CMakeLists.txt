cmake_minimum_required(VERSION 3.10)

project(
    CppProject
    VERSION 0.1
    DESCRIPTION "crossy-road-clone"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(main 
    src/main.cpp
    src/Block/Block.cpp
    src/Block/Stone.cpp
    src/Block/Star.cpp
    src/Block/Jump.cpp
    src/Block/Straight.cpp
    src/Block/Needle.cpp
    src/Ball.cpp
    src/Map.cpp
    )

target_link_libraries(main sfml-graphics sfml-window sfml-system)
include_directories(${PROJECT_SOURCE_DIR}/include)