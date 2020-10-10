cmake_minimum_required(VERSION 2.8)

project( HelloOpenCV )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/HelloOpenCV.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../Cmake/OpenCVCMake.cmake)
