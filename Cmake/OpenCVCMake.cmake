# Setting include and library directories and libraries 
# related to OpenCV

set(OPENCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/include)

set(OPENCV_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../opencv/build/lib)

set(OPENCV_LIBRARIES 	${OPENCV_LIBRARY_DIRS}/opencv_calib3d
			${OPENCV_LIBRARY_DIRS}/opencv_core
			${OPENCV_LIBRARY_DIRS}/opencv_dnn
			${OPENCV_LIBRARY_DIRS}/opencv_features2d
			${OPENCV_LIBRARY_DIRS}/opencv_flann
			${OPENCV_LIBRARY_DIRS}/opencv_gapi
			${OPENCV_LIBRARY_DIRS}/opencv_highgui
			${OPENCV_LIBRARY_DIRS}/opencv_imgcodecs
			${OPENCV_LIBRARY_DIRS}/opencv_imgproc
			${OPENCV_LIBRARY_DIRS}/opencv_ml
			${OPENCV_LIBRARY_DIRS}/opencv_objdetect
			${OPENCV_LIBRARY_DIRS}/opencv_photo
			${OPENCV_LIBRARY_DIRS}/opencv_stitching
			${OPENCV_LIBRARY_DIRS}/opencv_video
			${OPENCV_LIBRARY_DIRS}/opencv_videoio)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS} )

target_link_libraries( ${PROJECT_NAME} ${OPENCV_LIBRARIES})
