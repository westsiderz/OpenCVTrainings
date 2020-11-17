#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// The sizes of the image matrix
constexpr int cMatrixWidth = 600;
constexpr int cMatrixHeigth = 480;

void drawLines()
{
    // The thickness and type of the lines
    constexpr int cThickness = 5;
    constexpr int cLineType = LINE_8;

    // Create one image matrix with three channels and fill it with zeros
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);
	
    // Draw a line using an OpenCV function
	line( l_image, Point(0,0),
		Point(cMatrixWidth, cMatrixHeigth),
		Scalar( 255, 0, 0 ),
		cThickness,
		cLineType );
	
    // Draw an arrow using an OpenCV function
	arrowedLine( l_image, Point(0,cMatrixHeigth),
		Point(cMatrixWidth-50, 50),
		Scalar( 0, 0, 255 ),
		cThickness,
		cLineType );
    
    // Display the result
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawRectangles()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);
    
    // Set the line thickness and line size of the first rectangle  
    int l_thickness = 5;
	int l_lineType = FILLED;
	
    // Draw the first rectangle using an OpenCV function
	rectangle( l_image, Point(0,0),
		Point(cMatrixWidth, cMatrixHeigth),
		Scalar( 255, 0, 255 ),
		l_thickness,
		l_lineType );
		
    // Set the line thickness and line size of the second rectangle
    // FILLED thickness will draw a filled rectangle
	l_thickness = FILLED;
	l_lineType = LINE_8;
	
    // Draw the second rectangle. It will be filled
	rectangle( l_image, Point(50,50),
		Point(cMatrixWidth-50, cMatrixHeigth-50),
		Scalar( 255, 255, 0 ),
		l_thickness,
		l_lineType);
		
    // Set the line thickness and line size of the second rectangle
	l_thickness = 6;
	l_lineType = LINE_AA;
	
    // Draw the third rectangle
	rectangle( l_image, Rect(150,150, 
				cMatrixWidth-300, cMatrixHeigth-300),
		Scalar( 0, 255, 255 ),
		l_thickness,
		l_lineType);
    
    // Display the result
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawCircles()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    // Set the line thickness and line size of the first circle
    int l_thickness = 5;
    int l_lineType = FILLED;
    // Set the redius of the first circle
    int l_radius = cMatrixHeigth;

    // Draw the first circle using and OpenCV function
    circle(l_image,
        Point(cMatrixWidth/2, cMatrixHeigth/2),
        l_radius/2,
        Scalar(255, 0, 0),
        l_thickness,
        l_lineType);

    // Set the line thickness and line size of the second circle
    l_thickness = FILLED;
    l_lineType = LINE_8;

    // Draw the second circle using and OpenCV function. It will be filled
    circle(l_image,
        Point(cMatrixWidth / 2, cMatrixHeigth / 2),
        l_radius/4,
        Scalar(0, 0, 255),
        l_thickness,
        l_lineType);

    // Display the result
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawElipses()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    // Set the line thickness and line size of the first elipse
    int l_thickness = 3;
    int l_lineType = LINE_4;
    // Set the angle of the first elipse
    int l_angle = 45;

    // Draw the first elipse using an OpenCV function
    ellipse(l_image,
        Point(cMatrixWidth / 2, cMatrixHeigth / 2),
        Size(cMatrixHeigth / 4, cMatrixHeigth / 16),
        l_angle,
        0,
        360,
        Scalar(255, 0, 0),
        l_thickness,
        l_lineType);

    // Set the line thickness, line size and angle of the second elipse
    l_thickness = FILLED;
    l_lineType = LINE_8;
    l_angle = 90;

    // Draw the first elipse using an OpenCV function. It will be a filled elipse
    ellipse(l_image,
        RotatedRect(Point2f(cMatrixWidth / 2, cMatrixHeigth / 2), Size2f(cMatrixHeigth / 4, cMatrixHeigth / 16), static_cast<float>(l_angle)),
        Scalar(0, 0, 255),
        l_thickness,
        l_lineType);

    // Display the result
    namedWindow("Output", WINDOW_NORMAL);
    imshow("Output", l_image);
}

void drawPolygones()
{
    Mat l_image = Mat::zeros(cMatrixHeigth, cMatrixWidth, CV_8UC3);

    // Set the line type of the polygon
    int l_lineType = LINE_4;
    
    // Set the points for the first polygon.
    // It will be a rectangle
    Point l_triangle1[1][3];
    l_triangle1[0][0] = Point{50, 100};
    l_triangle1[0][1] = Point{100, 50};
    l_triangle1[0][2] = Point{150, 100};
    
    // Stored them in the required type
    const Point* l_trianglePoints1[1] = { l_triangle1[0] };
    // Set the number of points for the polygon
	int l_numberOfPoints[] = { 3 };
	
    // Draw a filled polygon using an OpenCV function
	fillPoly( l_image,
        l_trianglePoints1,
        l_numberOfPoints,
        1,
        Scalar( 0, 0, 255 ),
        l_lineType );
            
    // For the second OpenCV function we need a matrix
    // which support a 32bit signed type
    Mat l_triangle2 = Mat::zeros(1, 3, CV_32SC2);
    // Set the points for the second polygon.
    // It is a triangle
    int* l_triangle2Ptr = l_triangle2.ptr<int>(0);
    l_triangle2Ptr[0] = 150;
    l_triangle2Ptr[1] = 100;
    l_triangle2Ptr[2] = 200;
    l_triangle2Ptr[3] = 50;
    l_triangle2Ptr[4] = 250;
    l_triangle2Ptr[5] = 100;
          
    InputArrayOfArrays l_trianglePoints2(l_triangle2);
	
    // Draw a filled polygon using an OpenCV function
	fillPoly( l_image,
        l_trianglePoints2,
        Scalar( 0, 255, 0 ),
        l_lineType );
        
    // Set the points for the third polygon.
    // Again - triangle
    const Point l_triangle3[1][3] = {
							Point{250, 100}, 
							Point{300, 50},
							Point{350, 100} };
	const Point* l_trianglePoints3 = { l_triangle3[0] };
	
    // Draw a filled polygon using another OpenCV function
	fillConvexPoly( l_image,
        l_trianglePoints3,
        3,
        Scalar( 255, 0, 0 ),
        l_lineType );
        
    // Set the points for the fourth polygon.
    // Again - triangle
    Mat l_triangle4 = Mat::zeros(1, 3, CV_32SC2);
    int* l_triangle4Ptr = l_triangle4.ptr<int>(0);
    l_triangle4Ptr[0] = 350;
    l_triangle4Ptr[1] = 100;
    l_triangle4Ptr[2] = 400;
    l_triangle4Ptr[3] = 50;
    l_triangle4Ptr[4] = 450;
    l_triangle4Ptr[5] = 100;
          
    InputArray l_trianglePoints4(l_triangle4);
	
    // Draw a filled polygon using another OpenCV function
	fillConvexPoly( l_image,
        l_trianglePoints4,
        Scalar( 0, 255, 255 ),
        l_lineType );

    // Set the points for the fifth polygon.
    // Again - triangle
    const Point l_triangle5[1][3] = {
                            Point{450, 100},
                            Point{500, 50},
                            Point{550, 100} };
    const Point * l_trianglePoints5 = { l_triangle5[0] };
    const Point * const * l_trianglePointsPtr5 = { &l_trianglePoints5 };
    int l_numberOfPoints5[] = { 3 };

    // Draw an empty polygon using another OpenCV function
    polylines(l_image, 
        l_trianglePointsPtr5, 
        l_numberOfPoints5, 
        1, true, Scalar(255, 255, 0));

    // For the second OpenCV function we need a matrix
   // which support a 32bit signed type
    Mat l_triangle6 = Mat::zeros(1, 3, CV_32SC2);
    // Set the points for the second polygon.
    // It is a triangle
    int* l_triangle6Ptr = l_triangle6.ptr<int>(0);
    l_triangle6Ptr[0] = 250;
    l_triangle6Ptr[1] = 150;
    l_triangle6Ptr[2] = 300;
    l_triangle6Ptr[3] = 100;
    l_triangle6Ptr[4] = 350;
    l_triangle6Ptr[5] = 150;

    InputArrayOfArrays l_trianglePoints6(l_triangle6);

    // Draw an empty polygon using an OpenCV function
    polylines(l_image,
        l_trianglePoints6,
        true, Scalar(255, 0, 255));

    // Display the result
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
