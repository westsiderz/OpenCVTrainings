#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;


// Applies the morphological Gradient operation 
void applyHitAndMiss()
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
    
    // Create the output image matrix
    Mat l_outputImage = l_image.clone();
    
    // Creating the structuring element for the morphological operation              
	Mat kernel = (Mat_<int>(3, 3) <<
	1,  0, 0,
	1, -1, 0,
	1,  0, 0 );
      
    // Applying the Gradient Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_HITMISS, kernel );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}



int main()
{
    applyHitAndMiss();

    waitKey(0);
    return 0;
}
