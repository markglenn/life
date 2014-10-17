include(FindPkgConfig)

find_package( Boost REQUIRED COMPONENTS filesystem system )
find_package( OpenGL )
find_package( SDL2 REQUIRED )
find_package( SDL2_image REQUIRED )

FIND_LIBRARY(OpenGL_LIBRARY OpenGL )

add_subdirectory(life)

add_executable(g main.cpp)

INCLUDE_DIRECTORIES(
  ${SDL2_INCLUDE_DIR}
  ${SDLIMAGE_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/lib/glm
  ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES( g
  ${SDL2_LIBRARY}
  ${SDLIMAGE_LIBRARY}
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
