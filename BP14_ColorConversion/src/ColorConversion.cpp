#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Convert color image with alpha channel to color image without alpha channel
void convertColorBGRAToColorBGR()
{
    // Paths to the input and output image
    std::string l_pathToInputImage{ "../Resources/love.png" };
    std::string l_pathToOutputImage{ "../Resources/love_bgr.png" };

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

    // Create the output image matrix
    Mat l_outputImage;

    // Convert the colors
    cvtColor(l_image, l_outputImage, COLOR_BGRA2BGR);

    // Save the result image
    imwrite(l_pathToOutputImage, l_outputImage);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Convert color image to grayscale image
void convertColorToGrayscale()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

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
    
    // Create the output image matrix
    Mat l_outputImage;

    // Convert the colors
    cvtColor(l_image, l_outputImage, COLOR_BGR2GRAY);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Convert between different color spaces 
void convertBGRRBGColorToXXXColor()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

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
    Mat l_outputImageBGR2XYZ;
    Mat l_outputImageRGB2XYZ;
    Mat l_outputImageBGR2YCrCb;
    Mat l_outputImageRGB2YCrCb;
    Mat l_outputImageBGR2HSV;
    Mat l_outputImageRGB2HSV;
    Mat l_outputImageBGR2Lab;
    Mat l_outputImageRGB2Lab;
    Mat l_outputImageBGR2Luv;
    Mat l_outputImageRGB2Luv;
    Mat l_outputImageBGR2HLS;
    Mat l_outputImageRGB2HLS;

    // Convert the colors
    cvtColor(l_image, l_outputImageBGR2XYZ, COLOR_BGR2XYZ);
    cvtColor(l_image, l_outputImageRGB2XYZ, COLOR_RGB2XYZ);
    cvtColor(l_image, l_outputImageBGR2YCrCb, COLOR_BGR2YCrCb);
    cvtColor(l_image, l_outputImageRGB2YCrCb, COLOR_RGB2YCrCb);
    cvtColor(l_image, l_outputImageBGR2HSV, COLOR_BGR2HSV);
    cvtColor(l_image, l_outputImageRGB2HSV, COLOR_RGB2HSV);
    cvtColor(l_image, l_outputImageBGR2Lab, COLOR_BGR2Lab);
    cvtColor(l_image, l_outputImageRGB2Lab, COLOR_RGB2Lab);
    cvtColor(l_image, l_outputImageBGR2Luv, COLOR_BGR2Luv);
    cvtColor(l_image, l_outputImageRGB2Luv, COLOR_RGB2Luv);
    cvtColor(l_image, l_outputImageBGR2HLS, COLOR_BGR2HLS);
    cvtColor(l_image, l_outputImageRGB2HLS, COLOR_RGB2HLS);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result BGR2XYZ", WINDOW_NORMAL);
    cv::imshow("Result BGR2XYZ", l_outputImageBGR2XYZ);

    namedWindow("Result RGB2XYZ", WINDOW_NORMAL);
    cv::imshow("Result RGB2XYZ", l_outputImageRGB2XYZ);

    namedWindow("Result BGR2YCrCb", WINDOW_NORMAL);
    cv::imshow("Result BGR2YCrCb", l_outputImageBGR2YCrCb);

    namedWindow("Result RGB2YCrCb", WINDOW_NORMAL);
    cv::imshow("Result RGB2YCrCb", l_outputImageRGB2YCrCb);

    namedWindow("Result BGR2HSV", WINDOW_NORMAL);
    cv::imshow("Result BGR2HSV", l_outputImageBGR2HSV);

    namedWindow("Result RGB2HSV", WINDOW_NORMAL);
    cv::imshow("Result RGB2HSV", l_outputImageRGB2HSV);

    namedWindow("Result BGR2Lab", WINDOW_NORMAL);
    cv::imshow("Result BGR2Lab", l_outputImageBGR2Lab);

    namedWindow("Result RGB2Lab", WINDOW_NORMAL);
    cv::imshow("Result RGB2Lab", l_outputImageRGB2Lab);

    namedWindow("Result BGR2Luv", WINDOW_NORMAL);
    cv::imshow("Result BGR2Luv", l_outputImageBGR2Luv);

    namedWindow("Result RGB2Luv", WINDOW_NORMAL);
    cv::imshow("Result RGB2Luv", l_outputImageRGB2Luv);

    namedWindow("Result BGR2HLS", WINDOW_NORMAL);
    cv::imshow("Result BGR2HLS", l_outputImageBGR2HLS);

    namedWindow("Result RGB2HLS", WINDOW_NORMAL);
    cv::imshow("Result RGB2HLS", l_outputImageRGB2HLS);
}

int main()
{
    //convertColorBGRAToColorBGR();
    //convertColorToGrayscale();
    convertBGRRBGColorToXXXColor();

    waitKey(0);
    return 0;
}
