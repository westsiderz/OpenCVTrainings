#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

constexpr int cMatrixWidth = 600;
constexpr int cMatrixHeigth = 480;

void drawLines()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);
    
    constexpr int cThickness = 5;
	constexpr int cLineType = LINE_8;
	
	line( l_image, Point(0,0),
		Point(cMatrixWidth, cMatrixHeigth),
		Scalar( 255, 0, 0 ),
		cThickness,
		cLineType );
		
	arrowedLine( l_image, Point(0,cMatrixHeigth),
		Point(cMatrixWidth-50, 50),
		Scalar( 0, 0, 255 ),
		cThickness,
		cLineType );
    
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawRectangles()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);
    
    int l_thickness = 5;
	int l_lineType = LINE_8;
	
	rectangle( l_image, Point(0,0),
		Point(cMatrixWidth, cMatrixHeigth),
		Scalar( 255, 0, 255 ),
		l_thickness,
		l_lineType );
		
	l_thickness = FILLED;
	l_lineType = LINE_8;
	
	rectangle( l_image, Point(50,50),
		Point(cMatrixWidth-50, cMatrixHeigth-50),
		Scalar( 255, 255, 0 ),
		l_thickness,
		l_lineType);
		
	l_thickness = 6;
	l_lineType = LINE_AA;
	
	rectangle( l_image, Rect(150,150, 
				cMatrixWidth-300, cMatrixHeigth-300),
		Scalar( 0, 255, 255 ),
		l_thickness,
		l_lineType);
    
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}



int main()
{
    //drawLines();
	drawRectangles();
	
    waitKey(0);
    return 0;
}
