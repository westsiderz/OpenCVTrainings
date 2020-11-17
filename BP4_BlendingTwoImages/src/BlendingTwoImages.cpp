#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void blendImages()
{
    // Paths to the input images
    std::string l_pathToInputImage1{ "../Resources/city.jpg" };
    std::string l_pathToInputImage2{ "../Resources/autumn.jpg" };

    // Create an object to hold the image data of the first image
    Mat l_image1;
    // Read the image date from a file with no change to color scheme
    l_image1 = imread(l_pathToInputImage1, IMREAD_UNCHANGED);

    // Check if we have read the first image data correctly
    if (!l_image1.data)
    {
        std::cout << "No image 1 data \n";
        return;
    }

    // Create an object to hold the image data of the first image
    Mat l_image2;
    // Read the image date from a file with no change to color scheme
    l_image2 = imread(l_pathToInputImage2, IMREAD_UNCHANGED);

    // Check if we have read the second image data correctly
    if (!l_image2.data)
    {
        std::cout << "No image 2 data \n";
        return;
    }

    // Set the alpha of the first image
    float l_alpha1 = 0.5f;
    // Set the alpha of the second image
    float l_alpha2 = 1.0f - l_alpha1;
    // Set the gamma
    float l_gamma = 0.0f;
    // Create an object to hold the result
    Mat l_imageResult;

    // Call an OpenCV function to blend two images
    addWeighted(l_image1, l_alpha1, l_image2, l_alpha2, l_gamma, l_imageResult);

    // Input the first image
    namedWindow("Input1", WINDOW_NORMAL);
    imshow("Input1", l_image1);

    // Input the second image
    namedWindow("Input2", WINDOW_NORMAL);
    imshow("Input2", l_image2);

    // Input the result image
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_imageResult);
}
int main()
{
    blendImages();
    waitKey(0);
    return 0;
}
