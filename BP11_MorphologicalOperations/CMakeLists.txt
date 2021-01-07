project( BP11_MorphologicalOperations )

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Morphological.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include(${CMAKE_CURRENT_SOURCE_DIR}/../AdditionalCmake/OpenCVCMake.cmake)
