#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void erodeImage()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/kiss.jpg" };

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
    
    // Create the output image matrix
    Mat l_outputImage = l_image.clone();
    
    // Creating the structuring element for the morphological operation
    int l_erosionSize = 3;
    Mat l_erodingElement = getStructuringElement(  MORPH_RECT,
                       Size( 2*l_erosionSize + 1, 2*l_erosionSize+1 ),
                       Point( l_erosionSize, l_erosionSize ) );
      
    // Eroding the image                
    erode( l_image, l_outputImage, l_erodingElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}


int main()
{
    erodeImage();

    waitKey(0);
    return 0;
}
