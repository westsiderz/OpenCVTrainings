#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;

void printText(InputOutputArray inputImage)
{
    constexpr HersheyFonts l_fontType = HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX;
    constexpr int l_lineThickness = 2;
    // Calculate the font scale factor
    double l_fontScale{ getFontScaleFromHeight(l_fontType,
        24,
        l_lineThickness) };

    String l_text{ std::to_string(inputImage.cols()) + "x" + std::to_string(inputImage.rows()) + "px"};
    // Calculate the text string size
    Size l_textSize{ getTextSize(l_text,
        l_fontType,
        l_fontScale,
        l_lineThickness,
        nullptr) };

    // Find the center point for the text
    Point l_imageCenter{ inputImage.cols() / 2 - l_textSize.width / 2, inputImage.rows() / 2 - l_textSize.height / 2 };

    // Render the text
    putText(inputImage,
        l_text,
        l_imageCenter,
        l_fontType,
        l_fontScale,
        Scalar(255, 0, 0),
        l_lineThickness,
        LINE_8,
        false);
}

// Upscale an image
void upscaleImage(int upscaleFactor)
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
    
    // Create the output image matrix
    Mat l_outputImage = l_image.clone();

    // Upscale the image several times
    for (int i = 0; i < upscaleFactor / 2; ++i)
    {
        // Upscale the image. Upscaling can only be done to factor of two
        pyrUp(l_outputImage, l_outputImage, Size(l_outputImage.cols * 2, l_outputImage.rows * 2));
    }

    // Add the resolution values on top of the image
    printText(l_image);
    printText(l_outputImage);

    // Display the input image
    namedWindow("Input", WINDOW_AUTOSIZE);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_AUTOSIZE);
    cv::imshow("Result", l_outputImage);
}

// Downscale an image
void downscaleImage(int downscaleFactor)
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/love.png" };

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
    Mat l_outputImage = l_image.clone();

    for (int i = 0; i < downscaleFactor / 2; ++i)
    {
        // Upscale the image
        pyrDown(l_outputImage, l_outputImage, Size(l_outputImage.cols / 2, l_outputImage.rows / 2));
    }

    // Add the resolution values on top of the image
    printText(l_image);
    printText(l_outputImage);

    // Display the input image
    namedWindow("Input", WINDOW_AUTOSIZE);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_AUTOSIZE);
    cv::imshow("Result", l_outputImage);
}

// Downscale an image
void createImagePyramid(int level)
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/love.png" };

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
    std::vector<Mat> l_pyramid;
    buildPyramid(l_image, l_pyramid, level);

    for (int i = 0; i < l_pyramid.size(); ++i)
    {
        Mat l_result = l_pyramid.at(i);
        printText(l_result);
        namedWindow("Output" + std::to_string(i), WINDOW_AUTOSIZE);
        imshow("Output" + std::to_string(i), l_result);
    }
}


int main()
{
    //upscaleImage(4);
    //downscaleImage(2);
    createImagePyramid(3);

    waitKey(0);
    return 0;
}
