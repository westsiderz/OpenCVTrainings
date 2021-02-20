#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void blurImage()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

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
    
    // Create a destination image matrix
    Mat l_homogeneousBlurImage = l_image.clone();
    // Set the kernel size
    Size l_bluringKernelSize{ 13,13 };
    // Apply homogeneous blur
    blur(l_image, 
		 l_homogeneousBlurImage,
		 l_bluringKernelSize,
		 Point(-1,-1),
		 BORDER_DEFAULT);
		 
	Mat l_gaussianBlurImage = l_image.clone();
    l_bluringKernelSize.width = 25;
    l_bluringKernelSize.height = 25;
    // Apply Gaussian blur
	GaussianBlur( l_image,
				  l_gaussianBlurImage, 
				  l_bluringKernelSize, 
				  0, 0,
				  BORDER_DEFAULT );

    Mat l_medianBlurImage = l_image.clone();
    int l_medianKernelSize = 13;
    // Apply median blur
    medianBlur(l_image,
        l_medianBlurImage,
        l_medianKernelSize
        );

    Mat l_bilateralFilterBlurImage = l_image.clone();
    double l_bilateralFilterKernelSize = 15.0;
    // Apply Bilateral Filter blur
    bilateralFilter(l_image,
        l_bilateralFilterBlurImage,
        l_bilateralFilterKernelSize,
        l_bilateralFilterKernelSize*2, 
        l_bilateralFilterKernelSize/2,
        BORDER_DEFAULT);
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);
    
    // Display the Homogeneous Blur image
    namedWindow("Homogeneous Blur", WINDOW_NORMAL);
    cv::imshow("Homogeneous Blur", l_homogeneousBlurImage);
    
    // Display the Gaussion Blur image
    namedWindow("Gaussian Blur", WINDOW_NORMAL);
    cv::imshow("Gaussian Blur", l_gaussianBlurImage);

    // Display the Median Blur image
    namedWindow("Median Blur", WINDOW_NORMAL);
    cv::imshow("Median Blur", l_medianBlurImage);

    // Display the Bilateral Filter Blur image
    namedWindow("Bilateral Filter Blur", WINDOW_NORMAL);
    cv::imshow("Bilateral Filter Blur", l_bilateralFilterBlurImage);
}


int main()
{
    blurImage();

    waitKey(0);
    return 0;
}
