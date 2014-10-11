include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
find_package( Boost REQUIRED COMPONENTS filesystem system )
find_package( OpenGL )

FIND_LIBRARY(OpenGL_LIBRARY OpenGL )

add_subdirectory(life)

add_executable(g main.cpp)

INCLUDE_DIRECTORIES(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2IMAGE_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/lib/glm
  ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES( g
  ${SDL2_LIBRARIES}
  ${SDL2IMAGE_LIBRARIES}
  ${OpenGL_LIBRARY}
  ${Boost_LIBRARIES}
  life
)

set_source_files_properties( tags PROPERTIES GENERATED true )
add_custom_target(tags
  COMMAND ctags -R --extra=+f+q src include
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_dependencies(g tags)
