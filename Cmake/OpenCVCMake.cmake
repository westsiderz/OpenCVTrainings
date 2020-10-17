# Setting include and library directories and libraries 
# related to OpenCV

if(${CMAKE_SYSTEM_NAME} STREQUAL  "Linux")
set(OPENCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/build
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/calib3d/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/core/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/dnn/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/features2d/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/flann/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/gapi/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/highgui/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/imgcodecs/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/imgproc/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/ml/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/objdetect/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/photo/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/stitching/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/ts/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/video/include
			 ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/modules/videoio/include)

set(OPENCV_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/build/lib)

set(OPENCV_LIBRARIES 	${OPENCV_LIBRARY_DIRS}/libopencv_calib3d.so
			${OPENCV_LIBRARY_DIRS}/libopencv_core.so
			${OPENCV_LIBRARY_DIRS}/libopencv_dnn.so
			${OPENCV_LIBRARY_DIRS}/libopencv_features2d.so
			${OPENCV_LIBRARY_DIRS}/libopencv_flann.so
			${OPENCV_LIBRARY_DIRS}/libopencv_gapi.so
			${OPENCV_LIBRARY_DIRS}/libopencv_highgui.so
			${OPENCV_LIBRARY_DIRS}/libopencv_imgcodecs.so
			${OPENCV_LIBRARY_DIRS}/libopencv_imgproc.so
			${OPENCV_LIBRARY_DIRS}/libopencv_ml.so
			${OPENCV_LIBRARY_DIRS}/libopencv_objdetect.so
			${OPENCV_LIBRARY_DIRS}/libopencv_photo.so
			${OPENCV_LIBRARY_DIRS}/libopencv_stitching.so
			${OPENCV_LIBRARY_DIRS}/libopencv_video.so
			${OPENCV_LIBRARY_DIRS}/libopencv_videoio.so)
			
elseif(${CMAKE_SYSTEM_NAME} STREQUAL  "Windows")

message("Windows build not implemented yet")
			
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS} )

target_link_libraries( ${PROJECT_NAME} ${OPENCV_LIBRARIES})
