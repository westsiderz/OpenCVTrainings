#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace cv;

// Apply the Hough Line Transform operation to an image
void applyHoughLineTransform()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/table.jpg" };

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
    Mat l_outputImageCanny{};
    Mat l_outputHough{};

    // Remove any noise
    GaussianBlur(l_image, l_noiseRemovedImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Canny constants to play with
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;

    // Apply the canny edge detection
    Canny(l_noiseRemovedImage, l_outputImageCanny, c_lowerThreshold, c_upperThreshold, c_kernelSize, false);

    // Clone the Canny result to another matrix, where the lines will be drawn
    // It should be converted to BGR color in order to draw the lines on top
    cvtColor(l_outputImageCanny, l_outputHough, COLOR_GRAY2BGR);

    // Create constants and variables to hold the results from the Hough transform 
    constexpr double c_distanceResolution = 1;
    constexpr double c_angleResolution = CV_PI / 180;
    constexpr int c_threshold = 200;
    std::vector<Vec2f> l_foundLines;
    
    // Apply the Hough Line Transform
    HoughLines(l_outputImageCanny, l_foundLines, c_distanceResolution, c_angleResolution, c_threshold);

    // Draw the result lines
    for (size_t i = 0; i < l_foundLines.size(); ++i)
    {
        // Calculate the needed values and points coordinates
        constexpr int l_lineThickness = 2;
        float l_rho = l_foundLines.at(i)[0];
        float l_theta = l_foundLines.at(i)[1];
        double l_cosTheta = std::cos(l_theta);
        double l_sinTheta = sin(l_theta);
        double l_initXPoint = l_rho * l_cosTheta;
        double l_initYPoint = l_rho * l_sinTheta;
        Point l_startPoint{ cvRound(l_initXPoint + 1000 * (-l_sinTheta)), 
            cvRound(l_initYPoint + 1000 * (l_cosTheta)) };
        Point l_endPoint{ cvRound(l_initXPoint - 1000 * (-l_sinTheta)), 
            cvRound(l_initYPoint - 1000 * (l_cosTheta)) };

        // Draw the line
        line(l_outputHough, l_startPoint, l_endPoint, Scalar(0, 255, 0), l_lineThickness, LINE_AA);
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

// Apply the Hough Line Transform operation to an image
void applyHoughProbabilisticLineTransform()
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
    Mat l_outputImageCanny{};
    Mat l_outputHough{};

    // Remove any noise
    GaussianBlur(l_image, l_noiseRemovedImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Canny constants to play with
    constexpr int c_kernelSize = 3;
    constexpr double c_lowerThreshold = 30.0;
    constexpr double c_upperThreshold = c_lowerThreshold * 3.0;

    // Apply the canny edge detection
    Canny(l_noiseRemovedImage, l_outputImageCanny, c_lowerThreshold, c_upperThreshold, c_kernelSize, false);

    // Clone the Canny result to another matrix, where the lines will be drawn
    // It should be converted to BGR color in order to draw the lines on top
    cvtColor(l_outputImageCanny, l_outputHough, COLOR_GRAY2BGR);

    // Create constants and variables to hold the results from the Hough transform 
    constexpr double c_distanceResolution = 1;
    constexpr double c_angleResolution = CV_PI / 180;
    constexpr int c_threshold = 120;
    std::vector<Vec4i> l_foundLines;

    // Apply the Hough Line Transform
    HoughLinesP(l_outputImageCanny, l_foundLines, c_distanceResolution, c_angleResolution, c_threshold);

    // Draw the result lines
    for (size_t i = 0; i < l_foundLines.size(); ++i)
    {
        // Calculate the needed values and points coordinates
        constexpr int l_lineThickness = 2;
        Point l_startPoint{ l_foundLines.at(i)[0], l_foundLines.at(i)[1] };
        Point l_endPoint{ l_foundLines.at(i)[2], l_foundLines.at(i)[3] };

        // Draw the line
        line(l_outputHough, l_startPoint, l_endPoint, Scalar(0, 255, 0), l_lineThickness, LINE_AA);
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

void applyHoughLineTransformOnSetOfPoints()
{
    Mat l_transformResult{};
    std::vector<Vec3d> l_outputLines{};
    // The set of points to apply the Hough Line transform on
    std::vector<Vec2f> l_inputPoints
    {
        { 0.0f,   369.0f }, { 10.0f,  364.0f }, { 20.0f,  358.0f }, { 30.0f,  352.0f },
        { 40.0f,  346.0f }, { 50.0f,  341.0f }, { 60.0f,  335.0f }, { 70.0f,  329.0f },
        { 80.0f,  323.0f }, { 90.0f,  318.0f }, { 100.0f, 312.0f }, { 110.0f, 306.0f },
        { 120.0f, 300.0f }, { 130.0f, 295.0f }, { 140.0f, 289.0f }, { 150.0f, 284.0f },
        { 160.0f, 277.0f }, { 170.0f, 271.0f }, { 180.0f, 266.0f }, { 190.0f, 260.0f }
    };

    // The required constants
    constexpr int c_maxLines = 20;
    constexpr int c_threshold = 2;
    constexpr double c_distanceMin = 0.0;
    constexpr double c_distanceMax = 360.0;
    constexpr double c_distanceStep = 1.0;
    constexpr double c_angleMin = 0.0;
    constexpr double c_angleMax = CV_PI / 2.0;
    constexpr double c_angleStep = CV_PI / 180.0;

    // Apply the Hough Line transform
    HoughLinesPointSet(l_inputPoints, l_transformResult, c_maxLines, c_threshold,
        c_distanceMin, c_distanceMax, c_distanceStep, c_angleMin, c_angleMax, c_angleStep);

    // Copy the results
    l_transformResult.copyTo(l_outputLines);

    // Draw the result lines
    Mat l_result{ 600, 400, CV_8UC3, Scalar{255, 255, 255} };
    for (size_t i = 0; i < l_outputLines.size(); ++i)
    {
        // Calculate the needed values and points coordinates
        constexpr int l_lineThickness = 2;
        double l_rho = l_outputLines.at(i)[1];
        double l_theta = l_outputLines.at(i)[2];
        double l_cosTheta = std::cos(l_theta);
        double l_sinTheta = sin(l_theta);
        double l_initXPoint = l_rho * l_cosTheta;
        double l_initYPoint = l_rho * l_sinTheta;
        Point l_startPoint{ cvRound(l_initXPoint + 1000 * (-l_sinTheta)),
            cvRound(l_initYPoint + 1000 * (l_cosTheta)) };
        Point l_endPoint{ cvRound(l_initXPoint - 1000 * (-l_sinTheta)),
            cvRound(l_initYPoint - 1000 * (l_cosTheta)) };

        // Draw the line
        line(l_result, l_startPoint, l_endPoint, Scalar(0, 255, 0), l_lineThickness, LINE_AA);
    }

    // Display the input image
    namedWindow("Output", WINDOW_NORMAL);
    cv::imshow("Output", l_result);
}

int main()
{
    //applyHoughLineTransform();
    //applyHoughProbabilisticLineTransform();
    applyHoughLineTransformOnSetOfPoints();

    waitKey(0);
    return 0;
}
