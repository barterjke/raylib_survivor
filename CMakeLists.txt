cmake_minimum_required(VERSION 3.16)
project(raylib_survivor)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)


add_executable(raylib_survivor main.cpp headers.h Assets.cpp Assets.h Game.cpp Game.h Animation.cpp Animation.h Character.cpp Character.h Enemy.cpp Enemy.h Player.cpp Player.h Weapon.cpp Weapon.h Spawner.cpp Spawner.h util.h util.cpp CollisionSystem.cpp CollisionSystem.h)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)