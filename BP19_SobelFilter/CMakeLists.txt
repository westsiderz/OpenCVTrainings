project( BP19_SobelFilter )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Sobel.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
