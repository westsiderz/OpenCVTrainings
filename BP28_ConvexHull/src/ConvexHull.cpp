#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace cv;


// Add convex hull around the contours in an image
void addConvexHull()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/shapes.jpg" };

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
    blur(l_imageGrayscale, l_imageGrayscale, Size{ 3,3 });

    // Apply the canny edge detection
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;
    Mat l_cannyImage{};
    Canny(l_imageGrayscale, l_cannyImage, c_lowerThreshold, c_lowerThreshold, c_kernelSize);

    // Find the contours
    std::vector<std::vector<Point> > l_contours;
    std::vector<Vec4i> l_hierarchy;
    findContours(l_cannyImage, l_contours, l_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Get the convex hulls
    std::vector<std::vector<Point> > l_convexHull(l_contours.size());
    for (size_t i = 0; i < l_contours.size(); i++)
    {
        convexHull(l_contours[i], l_convexHull[i]);
    }

    // Draw the contours and the convex hulls
    Mat l_result = Mat::zeros(l_cannyImage.size(), CV_8UC3);
    for (int i = 0; i < l_contours.size(); i++)
    {
        const Scalar c_lineColor{ 0, 255, 0 };
        const Scalar c_convexHullLineColor{ 0, 0, 255 };
        constexpr int c_lineThickness = 1;
        drawContours(l_result, l_contours, i, c_lineColor, c_lineThickness, LINE_8, l_hierarchy);
        drawContours(l_result, l_convexHull, i, c_convexHullLineColor, c_lineThickness, LINE_8, l_hierarchy);
    }
    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_result);
}

int main()
{
    addConvexHull();

    waitKey(0);
    return 0;
}
