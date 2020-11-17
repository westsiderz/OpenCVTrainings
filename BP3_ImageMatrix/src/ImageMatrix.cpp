#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void initMat()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    // Create objects that will hold the image data
    Mat l_image1, l_image2;
    // Read the image date from a file with no change to color scheme
    l_image1 = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    // Check if we have read the image data correctly
    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Create another matrix object using the first one with size of 1x1
    Mat l_image3(l_image1, Rect(0, 0, 1, 1));

    // Assign the first object to the second one. Both will have the same image data
    // and change in the first will affect the second one
    l_image2 = l_image1;

    // Clone the first object into the second one. A change in the first object
    // will not affect the second one
    Mat l_image4 = l_image1.clone();

    // Create a matrix 2x2 with 3 channels in red color
    Mat l_image5{ 2, 2, CV_8UC3, Scalar{0, 0, 255} };

    // Output the matrix values
    std::cout << l_image5 << std::endl;
}

void reduceColor(uchar f_reductionValue)
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    Mat l_image1;
    // Read the image date from a file as a BGR color image
    l_image1 = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Get the number of channels in the image
    int l_channels = l_image1.channels();
    // Get the number of rows in the image matrix
    int l_rows = l_image1.rows;
    // Get the number of columns in the image matrix
    int l_columns = l_image1.cols * l_channels;

    // Traverse all the image rows
    for (int i = 0; i < l_rows; ++i)
    {
        // Get a pointer to the current row
        uchar* row = l_image1.ptr<uchar>(i);
        // Traverse each column in the matrix
        for (int j = 0; j < l_columns; ++j)
        {
            // Reduce the value of each channel for each pixel
            // Don't go below 0
            if (row[j] - f_reductionValue < 0)
            {
                row[j] = 0;
            }
            else
            {
                row[j] -= f_reductionValue;
            }
        }
    }
    
    // Create a window to display the image data
    namedWindow("Result", WINDOW_NORMAL);
    // Display the image data
    imshow("Result", l_image1);
}

void increaseColor(uchar f_increaseValue)
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    Mat l_image1;
    l_image1 = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    int l_channels = l_image1.channels();
    // In case of one channel (e.g. grayscale image)
    if (l_channels == 1)
    {
        // Iterate through each value in the matrix
        for (auto l_iterator = l_image1.begin<uchar>();
            l_iterator != l_image1.end<uchar>(); ++l_iterator)
        {
            // Increase the value of each pixel channel
            // Don't go over 255
            if (*l_iterator + f_increaseValue > 255)
            {
                *l_iterator = 255;
            }
            else
            {
                *l_iterator += f_increaseValue;
            } 
        }
    }
    // In case of three channels (e.g. color image)
    else if (l_channels == 3)
    {
        // Iterate through each value in the matrix
        // Process the values as vector of three points
        for (auto l_iterator = l_image1.begin<Vec3b>();
            l_iterator != l_image1.end<Vec3b>(); ++l_iterator)
        {
            // Increase the value of each pixel channel
            // Don't go over 255
            if((*l_iterator)[0] + f_increaseValue > 255)
            {
                (*l_iterator)[0] = 255;
            }
            else
            {
                (*l_iterator)[0] += f_increaseValue;
            }
            
            if ((*l_iterator)[1] + f_increaseValue > 255)
            {
                (*l_iterator)[1] = 255;
            }
            else
            {
                (*l_iterator)[1] += f_increaseValue;
            }

            if ((*l_iterator)[2] + f_increaseValue > 255)
            {
                (*l_iterator)[2] = 255;
            }
            else
            {
                (*l_iterator)[2] += f_increaseValue;
            }
        }
    }

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_image1);
}

void invertColor()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    Mat l_image1;
    l_image1 = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    int l_channels = l_image1.channels();
    if (l_channels == 1)
    {
        // Iterate over each row in the matrix
        for (int i = 0; i < l_image1.rows; ++i)
        {
            // Iterate over each column in the matrix
            for (int j = 0; j < l_image1.cols; ++j)
            {
                // Invert the value of each pixel channel
                l_image1.at<uchar>(i, j) = 255 - l_image1.at<uchar>(i, j);
            }
        }
    }
    else if (l_channels == 3)
    {
        // Get the imaxe matrix into another object
        Mat_<Vec3b> l_image2 = l_image1;

        // Iterate over each row in the matrix
        for (int i = 0; i < l_image1.rows; ++i)
        {
            // Iterate over each column in the matrix
            for (int j = 0; j < l_image1.cols; ++j)
            {
                // Invert the value of each pixel channel
                l_image2(i, j)[0] = 255 - l_image2(i, j)[0];
                l_image2(i, j)[1] = 255 - l_image2(i, j)[1];
                l_image2(i, j)[2] = 255 - l_image2(i, j)[2];
            }
        }

        // Assign the result to the original matrix
        l_image1 = l_image2;
    }

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_image1);
}

void invertColorUsingLut()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    Mat l_image1, l_image2;
    l_image1 = imread(l_pathToInputImage, IMREAD_COLOR);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    // Create a lookup table object
    Mat l_lookupTable( 1, 256, CV_8U );
    // Fill it with the reverse values - 255 to 0
    auto* p_lookUp = l_lookupTable.ptr();
    for (int i = 0; i < 256; ++i)
    {
        p_lookUp[i] = 255 - i;
    }

    // Using the lookup table change the values of the image data
    LUT(l_image1, l_lookupTable, l_image2);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_image2);
}

int main()
{
    initMat();
    reduceColor(100);
    increaseColor(100);
    invertColor();
    invertColorUsingLut();

    waitKey(0);
    return 0;
}
