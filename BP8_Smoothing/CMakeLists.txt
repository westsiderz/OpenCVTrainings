project( BP8_Smoothing)

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Smoothing.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
