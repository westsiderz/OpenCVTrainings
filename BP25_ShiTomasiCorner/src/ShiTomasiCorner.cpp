#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace cv;

// Apply the Shi-Tomasi Corner Detection operation to an image
void applyShiTomasiCornerDetection()
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

    // Convert the image to grayscale
    Mat l_imageGrayscale{};
    cvtColor(l_image, l_imageGrayscale, COLOR_BGR2GRAY);

    // Shi-Tomasi corner detection constants
    constexpr int const c_maximumNumberOfCorners = 100;
    constexpr int const c_blockSize = 3;
    constexpr int const c_apertureSize = 3;
    constexpr double const c_kParameter = 0.04;
    constexpr double const c_qualityLevel = 0.01;
    constexpr double const c_minimumDistance = 8.0f;

    // Apply the Shi-Tomasi corner detection
    std::vector<Point2f> l_detectedCorners{};
    goodFeaturesToTrack(l_imageGrayscale, l_detectedCorners, c_maximumNumberOfCorners,
        c_qualityLevel, c_minimumDistance, Mat(), c_blockSize, c_apertureSize, true, c_kParameter);

    // Draw circles around the detected corners
    constexpr int const c_radius = 8;
    constexpr int const c_lineThickness = 2;
    Mat l_results = l_image.clone();
    for (int i = 0; i < l_detectedCorners.size(); i++)
    {
        circle(l_results, l_detectedCorners[i], c_radius, Scalar(0, 0, 255), c_lineThickness, LINE_AA);
    }

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the Shi-Tomasi result image
    namedWindow("Result Shi-Tomasi Corner Detection", WINDOW_NORMAL);
    cv::imshow("Result Shi-Tomasi Corner Detection", l_results);
}


int main()
{
    applyShiTomasiCornerDetection();

    waitKey(0);
    return 0;
}
