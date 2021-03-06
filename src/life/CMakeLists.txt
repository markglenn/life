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
  texture.cpp
  logger.cpp
  device.cpp
  scene.cpp
  fixed_step_service.cpp
  hardware_buffer.cpp
  shader.cpp
  opengl_error_handler.cpp
  cell.cpp
)

INCLUDE_DIRECTORIES(
  ${Boost_INCLUDE_DIRS}
  ${SDL2_INCLUDE_DIR}
  ${SDL2IMAGE_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/lib/glm
  ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES(life ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${Boost_LIBRARIES} )
