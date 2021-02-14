#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Apply normalized box filter
void applyNormalizedBoxFilter()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/stormrider.jpg" };

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
    Mat l_outputImage;

    // Create the kernel
    constexpr int c_kernelSize = 3;
    constexpr float c_kernelDiv = static_cast<float>(c_kernelSize * c_kernelSize);
    Mat l_kernel = Mat::ones(Size{ c_kernelSize, c_kernelSize }, CV_32F) / c_kernelDiv;

    // Apply the filter
    filter2D(l_image, l_outputImage, -1, l_kernel);

   
    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Apply random linear filter
void applyRandomLinearFilter()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/stormrider.jpg" };

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
    Mat l_outputImage;

    // Create the kernel
    constexpr float c_kernelDiv = static_cast<float>(1.0f/16.0f);
    Mat l_kernel = c_kernelDiv * (Mat_<float>(3, 3) <<
        1,  2,  1,
        2,  4,  2,
        1,  2,  1);

    // Apply the filter
    filter2D(l_image, l_outputImage, -1, l_kernel);


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Apply normalized box filter using OpenCV ready function
void applyNormalizedBoxFilterOpenCVFunction()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/stormrider.jpg" };

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
    Mat l_outputImage;

    // Box sizes
    constexpr int c_boxWidth = 3;
    constexpr int c_boxHeight = 5;

    // Apply the filter
    boxFilter(l_image, l_outputImage, -1, Size{ c_boxWidth, c_boxHeight }, Point{ -1, -1 }, true);


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

int main()
{
    //applyNormalizedBoxFilter();
    //applyRandomLinearFilter();
    applyNormalizedBoxFilterOpenCVFunction();

    waitKey(0);
    return 0;
}
