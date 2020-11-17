#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void readColorJPGWriteSameType()
{
    // Paths to input and output image files
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_copy.jpg" };

    // Create an object that will hold the image data
    Mat l_image;
    // Read the image date from a file with no change to color scheme
    l_image = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    // Check if we have read the image data correctly
    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Create a window to display the image data
    namedWindow("Display Image", WINDOW_NORMAL);
    // Display the image data
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readColorJPGWriteDifferentType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_copy.png" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readColorPNGWriteDifferentType()
{
    std::string l_pathToInputImage{ "../Resources/love.png" };
    std::string l_pathToOutputImage{ "../Resources/love_copy.jpg" };

    Mat l_image;
    // Read the image date from a file as a BGR color image
    l_image = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readGrayscaleJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_gray_copy.jpg" };

    Mat l_image;
    // Read the image date from a file as a grayscale image
    l_image = imread(l_pathToInputImage, IMREAD_GRAYSCALE);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readGrayscalePNGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/love.png" };
    std::string l_pathToOutputImage{ "../Resources/love_gray_copy.png" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_GRAYSCALE);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readColorReducedJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_color_reduced_copy.jpg" };

    Mat l_image;
    // Read the image date from a file as a BGR color image with reduced size
    l_image = imread(l_pathToInputImage, IMREAD_REDUCED_COLOR_2);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

void readGrayscaleReducedJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_gray_reduced_copy.jpg" };

    Mat l_image;
    // Read the image date from a file as a grayscale image with reduced size
    l_image = imread(l_pathToInputImage, IMREAD_REDUCED_GRAYSCALE_4);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Display the result image
    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    // Save the image data into a new file
    imwrite(l_pathToOutputImage, l_image);
}

int main()
{
    readColorJPGWriteSameType();
    readColorJPGWriteDifferentType();
    readColorPNGWriteDifferentType();
    readGrayscaleJPGWriteSameType();
    readGrayscalePNGWriteSameType();
    readColorReducedJPGWriteSameType();
    readGrayscaleReducedJPGWriteSameType();

    waitKey(0);
    return 0;
}
