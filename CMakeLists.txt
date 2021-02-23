cmake_minimum_required(VERSION 3.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/AdditionalCmake/Macros.cmake)

project( OpenCVTrainings )

ProjectSubdirList(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
ENDFOREACH()
