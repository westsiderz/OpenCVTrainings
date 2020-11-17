project( BP4_BlendingTwoImages )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/BlendingTwoImages.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
