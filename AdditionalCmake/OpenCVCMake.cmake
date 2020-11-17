# Setting include and library directories and libraries 
# related to OpenCV

if(${CMAKE_SYSTEM_NAME} STREQUAL  "Linux")
set(OPENCV_INCLUDE_DIRS 	/usr/local/include/opencv4)

set(OPENCV_LIBRARY_DIRS 	/usr/local/lib)

set(OPENCV_LIBRARIES 		${OPENCV_LIBRARY_DIRS}/libopencv_calib3d.so
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
set(OPENCV_INCLUDE_DIRS 	${CMAKE_CURRENT_SOURCE_DIR}/../../opencv_build/install/include)

set(OPENCV_LIBRARY_DIRS 	${CMAKE_CURRENT_SOURCE_DIR}/../../opencv_build/install/x64/vc15/lib)

set(OPENCV_LIBRARIES 		${OPENCV_LIBRARY_DIRS}/opencv_calib3d450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_core450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_dnn450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_features2d450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_flann450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_highgui450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_imgcodecs450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_imgproc450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_ml450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_objdetect450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_photo450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_stitching450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_video450d.lib
							${OPENCV_LIBRARY_DIRS}/opencv_videoio450d.lib)
			
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS} )

target_link_libraries( ${PROJECT_NAME} ${OPENCV_LIBRARIES})
