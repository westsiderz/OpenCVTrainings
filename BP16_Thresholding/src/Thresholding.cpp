#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Apply threshold to a color image
void applyThreshold()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/car.jpg" };

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

    // Create the output image matrices
    Mat l_imageGray;
    Mat l_outputImage;

    // Convert the colorful image to grayscale
    cvtColor(l_image, l_imageGray, COLOR_BGRA2GRAY);

    // Apply thresholding
    threshold(l_imageGray, l_outputImage, 140, 255, THRESH_BINARY_INV);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the grayscale image
    namedWindow("Gray Image", WINDOW_NORMAL);
    cv::imshow("Gray Image", l_imageGray);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

int main()
{
    applyThreshold();

    waitKey(0);
    return 0;
}
