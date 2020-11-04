#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void blendImages()
{
    std::string l_pathToInputImage1{ "../Resources/city.jpg" };
    std::string l_pathToInputImage2{ "../Resources/autumn.jpg" };

    Mat l_image1;
    l_image1 = imread(l_pathToInputImage1, IMREAD_UNCHANGED);

    if (!l_image1.data)
    {
        std::cout << "No image 1 data \n";
        return;
    }

    Mat l_image2;
    l_image2 = imread(l_pathToInputImage2, IMREAD_UNCHANGED);

    if (!l_image2.data)
    {
        std::cout << "No image 2 data \n";
        return;
    }

    float l_alpha1 = 0.5f;
    float l_alpha2 = 1.0f - l_alpha1;
    float l_gamma = 0.0f;
    Mat l_imageResult;

    addWeighted(l_image1, l_alpha1, l_image2, l_alpha2, l_gamma, l_imageResult);

    namedWindow("Input1", WINDOW_NORMAL);
    imshow("Input1", l_image1);

    namedWindow("Input2", WINDOW_NORMAL);
    imshow("Input2", l_image2);

    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_imageResult);
}
int main()
{
    blendImages();
    waitKey(0);
    return 0;
}
