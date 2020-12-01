project( BP10_Erosion )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Erosion.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
