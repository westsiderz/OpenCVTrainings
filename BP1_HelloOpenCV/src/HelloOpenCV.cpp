#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
    // Create an object that will hold the image data
    Mat image;
    // Read the image date from a file as a BGR color image
    image = imread( "../Resources/tesla.jpg", IMREAD_COLOR );

    // Check if we have read the image data correctly
    if ( !image.data )
    {
        std::cout << "No image data \n";
        return -1;
    }

    // Create a window to display the image data
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    // Display the image data
    imshow("Display Image", image);

    waitKey(0);
    return 0;
}
