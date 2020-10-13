# Setting include and library directories and libraries 
# related to OpenCV

set(OPENCV_INCLUDE_DIRS /usr/local/include/opencv4)

set(OPENCV_LIBRARY_DIRS /usr/local/lib)

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

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS} )

target_link_libraries( ${PROJECT_NAME} ${OPENCV_LIBRARIES})
