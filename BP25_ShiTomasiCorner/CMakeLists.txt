project( BP25_ShiTomasiCorner )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/ShiTomasiCorner.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
