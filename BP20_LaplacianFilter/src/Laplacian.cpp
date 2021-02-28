#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Apply the Laplacian filter to an image
void applyLaplacianFilter()
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

    // Remove any noise
    GaussianBlur(l_image, l_image, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // Create the Laplacian result matrix
    Mat l_laplacian{};
    constexpr int c_depth = -1;
    constexpr int c_size = 3;
    constexpr double c_scale = 1.0;
    constexpr double c_delta = 0.0;

    // Apply the Sobel filters
    Laplacian(l_image, l_laplacian, c_depth, c_size, c_scale, c_delta);

    // Convert back to CV_8U
    convertScaleAbs(l_laplacian, l_outputImage);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}




int main()
{
    applyLaplacianFilter();

    waitKey(0);
    return 0;
}
