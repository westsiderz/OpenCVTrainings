#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void initMat()
{
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

    Mat l_image1, l_image2;
    l_image1 = imread(l_pathToInputImage, IMREAD_UNCHANGED);

    if (!l_image1.data)
    {
        std::cout << "No image data \n";
        return;
    }

    Mat l_image3(l_image1, Rect(0, 0, 1, 1));
    l_image2 = l_image1;

    Mat l_image4 = l_image1.clone();

    Mat l_image5{ 2, 2, CV_8UC3, Scalar{0, 0, 255} };

    std::cout << l_image5 << std::endl;
}

void reduceColor(uchar f_reductionValue)
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
    int l_rows = l_image1.rows;
    int l_columns = l_image1.cols * l_channels;

    for (int i = 0; i < l_rows; ++i)
    {
        uchar* row = l_image1.ptr<uchar>(i);
        for (int j = 0; j < l_columns; ++j)
        {
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
    
    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_image1);
}

void increaseColor(uchar f_reductionValue)
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
        for (auto l_iterator = l_image1.begin<uchar>();
            l_iterator != l_image1.end<uchar>(); ++l_iterator)
        {
            if (*l_iterator + f_reductionValue > 255)
            {
                *l_iterator = 255;
            }
            else
            {
                *l_iterator += f_reductionValue;
            } 
        }
    }
    else if (l_channels == 3)
    {
        for (auto l_iterator = l_image1.begin<Vec3b>();
            l_iterator != l_image1.end<Vec3b>(); ++l_iterator)
        {
            if((*l_iterator)[0] + f_reductionValue > 255)
            {
                (*l_iterator)[0] = 255;
            }
            else
            {
                (*l_iterator)[0] += f_reductionValue;
            }
            
            if ((*l_iterator)[1] + f_reductionValue > 255)
            {
                (*l_iterator)[1] = 255;
            }
            else
            {
                (*l_iterator)[1] += f_reductionValue;
            }

            if ((*l_iterator)[2] + f_reductionValue > 255)
            {
                (*l_iterator)[2] = 255;
            }
            else
            {
                (*l_iterator)[2] += f_reductionValue;
            }
        }
    }

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
        for (int i = 0; i < l_image1.rows; ++i)
        {
            for (int j = 0; j < l_image1.cols; ++j)
            {
                l_image1.at<uchar>(i, j) = 255 - l_image1.at<uchar>(i, j);
            }
        }
    }
    else if (l_channels == 3)
    {
        Mat_<Vec3b> l_image2 = l_image1;

        for (int i = 0; i < l_image1.rows; ++i)
        {
            for (int j = 0; j < l_image1.cols; ++j)
            {
                l_image2(i, j)[0] = 255 - l_image2(i, j)[0];
                l_image2(i, j)[1] = 255 - l_image2(i, j)[1];
                l_image2(i, j)[2] = 255 - l_image2(i, j)[2];
            }
        }

        l_image1 = l_image2;
    }

    namedWindow("Result", WINDOW_NORMAL);
    imshow("Result", l_image1);
}

int main()
{
     initMat();
    // reduceColor(100);
    // increaseColor(100);
    invertColor();

    waitKey(0);
    return 0;
}
