#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace cv;

// Apply the Hough Circle Transform operation to an image
void applyHoughCircleTransform()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/circles.jpg" };

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

    // Convert the image to grayccale
    Mat l_imageGrayscale{};
    cvtColor(l_image, l_imageGrayscale, COLOR_BGR2GRAY);

    // Create the output image matrices
    Mat l_noiseRemovedImage{};
    Mat l_outputImageCanny{};
    Mat l_outputHough = l_image.clone();

    // Remove any noise
    GaussianBlur(l_imageGrayscale, l_noiseRemovedImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Canny constants to play with
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;

    // Apply the canny edge detection
    Canny(l_noiseRemovedImage, l_outputImageCanny, c_lowerThreshold, c_upperThreshold, c_kernelSize, false);

    // Create constants and variables to hold the results from the Hough transform 
    constexpr double c_accumulatorResolution = 1;
    const double c_minimumDistance = l_outputImageCanny.rows/16;
    constexpr double c_param1 = 100;
    constexpr double c_param2 = 35;
    constexpr double c_minimumRadius = 1;
    constexpr double c_maximumRadius = 300;
    std::vector<Vec3f> l_foundCircles;
    
    // Apply the Hough Circle Transform
    HoughCircles(l_outputImageCanny, l_foundCircles, HOUGH_GRADIENT, c_accumulatorResolution, c_minimumDistance, 
        c_param1, c_param2, c_minimumRadius, c_maximumRadius);

    // Draw the result lines
    for (size_t i = 0; i < l_foundCircles.size(); ++i)
    {
        constexpr int c_lineThickness = 3;
        Vec3i l_currentCircle{ l_foundCircles.at(i) };
        Point l_center{ l_currentCircle[0], l_currentCircle[1] };
        int l_radius{ l_currentCircle[2] };
        circle(l_outputHough, l_center, l_radius, Scalar(0, 0, 255), c_lineThickness, LINE_AA);
    }

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the Canny result image
    namedWindow("Result Canny", WINDOW_NORMAL);
    cv::imshow("Result Canny", l_outputImageCanny);

    // Display the Hough Transform result image
    namedWindow("Result Hough Transform", WINDOW_NORMAL);
    cv::imshow("Result Hough Transform", l_outputHough);
}


int main()
{
    applyHoughCircleTransform();

    waitKey(0);
    return 0;
}
