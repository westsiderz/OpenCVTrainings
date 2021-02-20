#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

void displayText()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/city.jpg" };

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

    constexpr HersheyFonts l_fontType = HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX;
    constexpr int l_lineThickness = 5;
    // Calculate the font scale factor
    double l_fontScale{ getFontScaleFromHeight(l_fontType,
        72,
        l_lineThickness) };

    const String l_text{ "With my hommie" };
    // Calculate the text string size
    Size l_textSize{ getTextSize(l_text,
        l_fontType,
        l_fontScale,
        l_lineThickness,
        nullptr) };

    // Find the center point for the text
    Point l_imageCenter{ l_image1.cols / 2 - l_textSize.width / 2, l_image1.rows / 2 - l_textSize.height / 2 };

    // Render the text
    putText(l_image1,
        l_text,
        l_imageCenter,
        l_fontType,
        l_fontScale,
        Scalar(255, 0, 0),
        l_lineThickness,
        LINE_8,
        false);

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image1);
}


int main()
{
    displayText();

    waitKey(0);
    return 0;
}
