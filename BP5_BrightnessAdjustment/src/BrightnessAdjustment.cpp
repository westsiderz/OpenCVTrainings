#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void increaseBrightness()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/underexposed2.jpg" };

    // Create an object to hold the image data of the first image
    Mat l_image1;
    // Read the image date from a file with no change to color scheme
    l_image1 = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    // Check if we have read the first image data correctly
    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Get the number of channels in the image
    int l_channels = l_image1.channels();
    // Set the alpha
    float l_alpha = 1.3f;
    // Set the beta
    int l_beta = 40;

    // Create one matrix to hold the result of the adjustment. Fill it with zeros
    Mat l_resultImage = Mat::zeros(l_image1.size(), l_image1.type());
    
    // In case of one channel (e.g. grayscale image)
    if (l_channels == 1)
    {
        // Iterate over each pixel
        auto l_iteratorResult = l_resultImage.begin<uchar>();
        for (auto l_iterator = l_image1.begin<uchar>();
            l_iterator != l_image1.end<uchar>(); ++l_iterator)
        {
            // Calculate the new value of the pixel
            // saturate_cast casts the result to the given type and keeps the value inside the 
            // type's possible values borders. 
            *l_iteratorResult = saturate_cast<uchar>((l_alpha * (*l_iterator)) + l_beta);

            // Move to the next pixel channel
            ++l_iteratorResult;
        }
    }
    // In case of three channels (e.g. color image)
    else if (l_channels == 3)
    {
        // Iterate over each pixel as it is a Vector of three values
        auto l_iteratorResult = l_resultImage.begin<Vec3b>();
        for (auto l_iterator = l_image1.begin<Vec3b>();
            l_iterator != l_image1.end<Vec3b>(); ++l_iterator)
        {
            // Calculate the new value of the pixel
            // saturate_cast casts the result to the given type and keeps the value inside the 
            // type's possible values borders.
            (*l_iteratorResult)[0] = saturate_cast<uchar>((l_alpha * ((*l_iterator)[0])) + l_beta);
            (*l_iteratorResult)[1] = saturate_cast<uchar>((l_alpha * ((*l_iterator)[1])) + l_beta);
            (*l_iteratorResult)[2] = saturate_cast<uchar>((l_alpha * ((*l_iterator)[2])) + l_beta);
            ++l_iteratorResult;
        }
    }

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image1);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_resultImage);
}

void correctGamma()
{
    std::string l_pathToInputImage{ "../Resources/underexposed2.jpg" };

    Mat l_image1;
    l_image1 = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    int l_channels = l_image1.channels();
    float l_gamma = 0.4f;

    Mat l_resultImage = Mat::zeros(l_image1.size(), l_image1.type());

    if (l_channels == 1)
    {
        auto l_iteratorResult = l_resultImage.begin<uchar>();
        for (auto l_iterator = l_image1.begin<uchar>();
            l_iterator != l_image1.end<uchar>(); ++l_iterator)
        {
            *l_iteratorResult = saturate_cast<uchar>(pow(*l_iterator / 255.0, l_gamma) * 255.0);
            ++l_iteratorResult;
        }
    }
    else if (l_channels == 3)
    {
        auto l_iteratorResult = l_resultImage.begin<Vec3b>();
        for (auto l_iterator = l_image1.begin<Vec3b>();
            l_iterator != l_image1.end<Vec3b>(); ++l_iterator)
        {
            (*l_iteratorResult)[0] = saturate_cast<uchar>(pow((*l_iterator)[0] / 255.0, l_gamma) * 255.0);
            (*l_iteratorResult)[1] = saturate_cast<uchar>(pow((*l_iterator)[1] / 255.0, l_gamma) * 255.0);
            (*l_iteratorResult)[2] = saturate_cast<uchar>(pow((*l_iterator)[2] / 255.0, l_gamma) * 255.0);
            ++l_iteratorResult;
        }
    }

    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image1);
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_resultImage);
}


int main()
{
    increaseBrightness();
    correctGamma();

    waitKey(0);
    return 0;
}
