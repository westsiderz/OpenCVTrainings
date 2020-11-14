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
	int l_lineType = FILLED;
	
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

void drawCircles()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    int l_thickness = 5;
    int l_lineType = FILLED;
    int l_radius = cMatrixHeigth;

    circle(l_image,
        Point(cMatrixWidth/2, cMatrixHeigth/2),
        l_radius/2,
        Scalar(255, 0, 0),
        l_thickness,
        l_lineType);

    l_thickness = FILLED;
    l_lineType = LINE_8;

    circle(l_image,
        Point(cMatrixWidth / 2, cMatrixHeigth / 2),
        l_radius/4,
        Scalar(0, 0, 255),
        l_thickness,
        l_lineType);

    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawElipses()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    int l_thickness = 3;
    int l_lineType = LINE_4;
    int l_angle = 45;

    ellipse(l_image,
        Point(cMatrixWidth / 2, cMatrixHeigth / 2),
        Size(cMatrixHeigth / 4, cMatrixHeigth / 16),
        l_angle,
        0,
        360,
        Scalar(255, 0, 0),
        l_thickness,
        l_lineType);

    l_thickness = FILLED;
    l_lineType = LINE_8;
    l_angle = 90;

    ellipse(l_image,
        RotatedRect(Point2f(cMatrixWidth / 2, cMatrixHeigth / 2), Size2f(cMatrixHeigth / 4, cMatrixHeigth / 16), static_cast<float>(l_angle)),
        Scalar(0, 0, 255),
        l_thickness,
        l_lineType);

    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawPolygones()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    int l_lineType = LINE_4;
    
    // Fill Poly
    
    Point l_triangle1[1][3];
    l_triangle1[0][0] = Point{50, 100};
    l_triangle1[0][1] = Point{100, 50};
    l_triangle1[0][2] = Point{150, 100};
    
    const Point* l_trianglePoints1[1] = { l_triangle1[0] };
	int l_numberOfPoints[] = { 3 };
	
	fillPoly( l_image,
        l_trianglePoints1,
        l_numberOfPoints,
        1,
        Scalar( 0, 0, 255 ),
        l_lineType );
            
    Mat l_triangle2 = Mat::zeros(1, 3, CV_32SC2);
    int* l_triangle2Ptr = l_triangle2.ptr<int>(0);
    l_triangle2Ptr[0] = 150;
    l_triangle2Ptr[1] = 100;
    l_triangle2Ptr[2] = 200;
    l_triangle2Ptr[3] = 50;
    l_triangle2Ptr[4] = 250;
    l_triangle2Ptr[5] = 100;
          
    InputArrayOfArrays l_trianglePoints2(l_triangle2);
	
	fillPoly( l_image,
        l_trianglePoints2,
        Scalar( 0, 255, 0 ),
        l_lineType );
        
    
    // Fill Convex Poly
    
    const Point l_triangle3[1][3] = {
							Point{250, 100}, 
							Point{300, 50},
							Point{350, 100} };
	const Point* l_trianglePoints3 = { l_triangle3[0] };
	
	fillConvexPoly( l_image,
        l_trianglePoints3,
        3,
        Scalar( 255, 0, 0 ),
        l_lineType );
            
    Mat l_triangle4 = Mat::zeros(1, 3, CV_32SC2);
    int* l_triangle4Ptr = l_triangle4.ptr<int>(0);
    l_triangle4Ptr[0] = 350;
    l_triangle4Ptr[1] = 100;
    l_triangle4Ptr[2] = 400;
    l_triangle4Ptr[3] = 50;
    l_triangle4Ptr[4] = 450;
    l_triangle4Ptr[5] = 100;
          
    InputArray l_trianglePoints4(l_triangle4);
	
	fillConvexPoly( l_image,
        l_trianglePoints4,
        Scalar( 0, 255, 255 ),
        l_lineType );

    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

int main()
{
    //drawLines();
	//drawRectangles();
    //drawCircles();
    //drawElipses();
    drawPolygones();
	
    waitKey(0);
    return 0;
}
