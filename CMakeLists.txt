cmake_minimum_required( VERSION 3.10 )
project( app_project VERSION 0.1 LANGUAGES C )

add_executable( triangle "triangle.c" )
add_executable( libsdl2 "libsdl2.c" )

find_package( SDL2 REQUIRED )
target_link_libraries( libsdl2 ${SDL2_LIBRARIES} )
