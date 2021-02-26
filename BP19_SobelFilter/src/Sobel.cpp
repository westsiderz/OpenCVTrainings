#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Apply the Sobel filter to an image
void applySobelFilter()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/youngBlood.jpg" };

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
    Mat l_outputImage{};

    // Create the Sobel results
    Mat l_xSobel{};
    Mat l_ySobel{};
    constexpr int c_depth = -1;
    constexpr int c_size = 3;
    constexpr double c_scale = 1.0;
    constexpr double c_delta = 0.0;

    // Apply the Sobel filters
    Sobel(l_image, l_xSobel, c_depth, 0, 1, c_size, c_scale, c_delta);
    Sobel(l_image, l_ySobel, c_depth, 1, 0, c_size, c_scale, c_delta);

    // Convert back to CV_8U
    Mat l_xAbsSobel{};
    Mat l_yAbsSobel{};
    convertScaleAbs(l_xSobel, l_xAbsSobel);
    convertScaleAbs(l_ySobel, l_yAbsSobel);

    constexpr double c_alpha = 0.5;
    constexpr double c_beta = 0.5;
    addWeighted(l_xAbsSobel, c_alpha, l_yAbsSobel, c_beta, 0, l_outputImage);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}


int main()
{
    applySobelFilter();

    waitKey(0);
    return 0;
}
