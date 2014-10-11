project(life)
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

add_library(life
  gametime.cpp
  kernel.cpp
  folder_archive.cpp
  composite_archive.cpp
  game_window.cpp
  input_handler.cpp
  sdl_istream_adapter.cpp
  resource.cpp
  texture.cpp
  logger.cpp
  device.cpp
  scene.cpp
)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/lib/glm ${CMAKE_SOURCE_DIR}/include)
TARGET_LINK_LIBRARIES(life ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${Boost_LIBRARIES} )
