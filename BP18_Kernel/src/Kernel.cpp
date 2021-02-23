#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Get filter coefficients for computing spatial image derivative
// using Sobel algo
void getDerivativeKernelSobel()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbol.jpg" };

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

    // Create the kernel
    Mat l_xKernel{};
    Mat l_yKernel{};
    getDerivKernels(l_xKernel, l_yKernel, 0, 1, 7, true);

    // Apply the filter
    sepFilter2D(l_image, l_outputImage, -1, l_xKernel, l_yKernel);


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Get filter coefficients for computing spatial image derivative
// using Scharr algo
void getDerivativeKernelScharr()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbol.jpg" };

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

    // Create the kernel
    Mat l_xKernel{};
    Mat l_yKernel{};
    getDerivKernels(l_xKernel, l_yKernel, 0, 1, FILTER_SCHARR, true);

    // Apply the filter
    sepFilter2D(l_image, l_outputImage, -1, l_xKernel, l_yKernel);

   
    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Get Gabor filter coefficients
void getGaborKernelMatrix()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/hazard.jpg" };

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

    // Create the kernel
    constexpr int c_size = 3;
    constexpr double c_sigma = 10.0;
    constexpr double c_theta = 60.0;
    constexpr double c_lambda = 30.0;
    constexpr double c_gamma = 0.25;
    Mat l_kernel = getGaborKernel(Size{ c_size,c_size }, c_sigma, c_theta, c_lambda, c_gamma);

    // Apply the filter
    filter2D(l_image, l_outputImage, -1, l_kernel);


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Get Gaussian filter coefficients
void getGaussianKernelMatrix()
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
    Mat l_outputImage{};

    // Create the kernel
    constexpr int c_size = 7;
    constexpr double c_sigma = 10.0;
    Mat l_kernel = getGaussianKernel(c_size, c_sigma);

    // Apply the filter
    filter2D(l_image, l_outputImage, -1, l_kernel);


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

int main()
{
    //getDerivativeKernelSobel();
    //getDerivativeKernelScharr();
    //getGaborKernelMatrix();
    getGaussianKernelMatrix();

    waitKey(0);
    return 0;
}
