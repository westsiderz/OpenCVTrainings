cmake_minimum_required(VERSION 2.8)

project( HelloOpenCV )

add_executable( HelloOpenCV ./src/HelloOpenCV.cpp )

find_package(OpenCV REQUIRED PATHS /user/local NO_DEFAULT_PATH)

target_include_directories(HelloOpenCV PUBLIC ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( HelloOpenCV ${OpenCV_LIBS})
