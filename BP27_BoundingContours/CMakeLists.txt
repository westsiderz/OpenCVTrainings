project( BP27_BoundingContours )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/BoundingContours.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
