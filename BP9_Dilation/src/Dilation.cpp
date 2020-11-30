#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void dilateImage()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbol.jpg" };

    // Create an object to hold the image data of the first image
    Mat l_image;
    // Read the image date from a file with no change to color scheme
    l_image = imread(l_pathToInputImage, IMREAD_UNCHANGED);

	// Check if we have read the first image data correctly
    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }
    
    Mat l_outputImage = l_image.clone();
    
    int l_dilationSize = 19;
    Mat l_dilatingElement = getStructuringElement(  MORPH_ELLIPSE,
                       Size( 2*l_dilationSize + 1, 2*l_dilationSize+1 ),
                       Point( l_dilationSize, l_dilationSize ) );
                       
    dilate( l_image, l_outputImage, l_dilatingElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}


int main()
{
    dilateImage();

    waitKey(0);
    return 0;
}
