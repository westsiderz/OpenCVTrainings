#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void readColorJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_copy.jpg" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

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

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    imwrite(l_pathToOutputImage, l_image);
}

void readColorPNGWriteDifferentType()
{
    std::string l_pathToInputImage{ "../Resources/love.png" };
    std::string l_pathToOutputImage{ "../Resources/love_copy.jpg" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    imwrite(l_pathToOutputImage, l_image);
}

void readGrayscaleJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_gray_copy.jpg" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_GRAYSCALE);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

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

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    imwrite(l_pathToOutputImage, l_image);
}

void readColorReducedJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_color_reduced_copy.jpg" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_REDUCED_COLOR_2);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    imwrite(l_pathToOutputImage, l_image);
}

void readGrayscaleReducedJPGWriteSameType()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };
    std::string l_pathToOutputImage{ "../Resources/city_gray_reduced_copy.jpg" };

    Mat l_image;
    l_image = imread(l_pathToInputImage, IMREAD_REDUCED_GRAYSCALE_4);

    if (!l_image.data)
    {
        std::cout << "No image data \n";
        return;
    }

    namedWindow("Display Image", WINDOW_NORMAL);
    imshow("Display Image", l_image);

    imwrite(l_pathToOutputImage, l_image);
}

int main()
{
    // readColorJPGWriteSameType();
    // readColorJPGWriteDifferentType();
    // readColorPNGWriteDifferentType();
    // readGrayscaleJPGWriteSameType();
    // readGrayscalePNGWriteSameType();
    // readColorReducedJPGWriteSameType();
     readGrayscaleReducedJPGWriteSameType();

    waitKey(0);
    return 0;
}
