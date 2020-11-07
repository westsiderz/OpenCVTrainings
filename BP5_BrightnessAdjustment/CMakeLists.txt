cmake_minimum_required(VERSION 3.0)

project( BrightnessAdjustment )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/BrightnessAdjustment.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../Cmake/OpenCVCMake.cmake)
