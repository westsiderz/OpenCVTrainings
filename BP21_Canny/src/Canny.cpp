#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Apply the Canny Edge Detector to an image
void applyCanny()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/building.jpg" };

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
    Mat l_noiseRemovedImage{};
    Mat l_outputImage{};

    // Remove any noise
    GaussianBlur(l_image, l_noiseRemovedImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Canny constants to play with
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;

    // Apply the canny edge detection
    Canny(l_noiseRemovedImage, l_outputImage, c_lowerThreshold, c_upperThreshold, c_kernelSize, false);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Apply the Canny Edge Detector to an image
void applyCannyWithDerivatives()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/building.jpg" };

    // Create an object to hold the image data of the first image
    Mat l_image;
    // Read the image date from a file with no change to color scheme
    l_image = imread(l_pathToInputImage, IMREAD_GRAYSCALE);

    // Check if we have read the first image data correctly
    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Create the output image matrices
    Mat l_noiseRemovedImage{};
    Mat l_outputImage{};

    // Remove any noise
    GaussianBlur(l_image, l_noiseRemovedImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Canny constants to play with
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;

    // Create the gradients results
    Mat l_xGradient{};
    Mat l_yGradient{};

    // Apply the spatial gradient
    spatialGradient(l_noiseRemovedImage, l_xGradient, l_yGradient, c_kernelSize);

    // Apply the canny edge detection
    Canny(l_xGradient, l_yGradient, l_outputImage, c_lowerThreshold, c_upperThreshold, false);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}


int main()
{
    //applyCanny();
    applyCannyWithDerivatives();

    waitKey(0);
    return 0;
}
