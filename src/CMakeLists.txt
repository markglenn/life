include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
FIND_PACKAGE( Boost REQUIRED COMPONENTS filesystem system )

add_subdirectory(life)

add_executable(game main.cpp)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/lib/glm ${CMAKE_SOURCE_DIR}/include)
TARGET_LINK_LIBRARIES(game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${Boost_LIBRARIES} life)
