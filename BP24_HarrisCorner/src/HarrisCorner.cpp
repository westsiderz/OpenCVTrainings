#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace cv;

// Apply the Harris Corner Detection operation to an image
void applyHarrisCornerDetection()
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

    // Harris corner detection constants
    constexpr int const c_blockSize = 2;
    constexpr int const c_apertureSize = 3;
    constexpr double const c_kParameter = 0.06;
    constexpr int const c_threshold = 120;

    // Apply the Harris corner detection
    Mat l_outputHarris = Mat::zeros(l_image.size(), CV_32FC1);
    cornerHarris(l_imageGrayscale, l_outputHarris, c_blockSize, c_apertureSize, c_kParameter);

    // Normalize the result
    Mat l_outputHarrisNormalized, l_outputHarrisScaled;
    normalize(l_outputHarris, l_outputHarrisNormalized, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(l_outputHarrisNormalized, l_outputHarrisScaled);

    // Draw circles around the detected corners
    constexpr int const c_radius = 4;
    constexpr int const c_lineThickness = 2;
    for (int i = 0; i < l_outputHarrisNormalized.rows; i++)
    {
        for (int j = 0; j < l_outputHarrisNormalized.cols; j++)
        {
            if ((int)l_outputHarrisNormalized.at<float>(i, j) > c_threshold)
            {
                circle(l_outputHarrisScaled, Point(j, i), c_radius, Scalar(0, 0, 255), c_lineThickness, LINE_AA);
            }
        }
    }

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the Hough Transform result image
    namedWindow("Result Harris Corner Detection", WINDOW_NORMAL);
    cv::imshow("Result Harris Corner Detection", l_outputHarrisScaled);
}


int main()
{
    applyHarrisCornerDetection();

    waitKey(0);
    return 0;
}
