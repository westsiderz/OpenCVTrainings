#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;

// Apply translation to an image
void applyTranslation()
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
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set the initial and end points of the first transformation
    Point2f l_initialPoint[]
    {
        {0.0f, 0.0f},                   // Point 1 coordinates
        {l_image.cols - 1.0f, 0.0f},    // Point 2 coordinates
        {0.0f, l_image.rows - 1.0f}     // Point 3 coordinates
    };

    Point2f l_endPoint[]
    {
        {50.0f, 50.0f},                         // Point 1 coordinates
        {50.0f + l_image.cols - 1.0f, 50.0f},   // Point 2 coordinates
        {50.0f, 50.0f + l_image.rows - 1.0f}    // Point 3 coordinates
    };

    // Set the initial and end points as arrays of the second transformation
    Mat l_srcArray = (Mat_<float>(3, 2) <<
        0.0f, 0.0f,                         // Point 1 coordinates
        l_image.cols - 1.0f, 0.0f,          // Point 2 coordinates
        0.0f, l_image.rows - 1.0f           // Point 3 coordinates
    );

    Mat l_dstArray = (Mat_<float>(3, 2) <<
        100.0f, -100.0f,                            // Point 1 coordinates
        100.0f + l_image.cols - 1.0f, -100.0f,      // Point 2 coordinates
        100.0f, l_image.rows - 1.0f - 100.0f        // Point 3 coordinates
    );

    // Calculate the transformation matrices
    Mat l_transformationMatrix1 = getAffineTransform(l_initialPoint, l_endPoint);
    Mat l_transformationMatrix2 = getAffineTransform(l_srcArray, l_dstArray);

    // Apply the transformations
    warpAffine(l_image, l_outputImage1, l_transformationMatrix1, l_outputImage1.size());
    warpAffine(l_image, l_outputImage2, l_transformationMatrix2, l_outputImage2.size());


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result 1", WINDOW_NORMAL);
    cv::imshow("Result 1", l_outputImage1);

    namedWindow("Result 2", WINDOW_NORMAL);
    cv::imshow("Result 2", l_outputImage2);
}

// Apply reflection to an image
void applyReflection()
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
    Mat l_outputImageX;
    Mat l_outputImageY;

    // Set the initial and end points of the first transformation
    Point2f l_initialPoint[]
    {
        {0.0f, 0.0f},                   // Point 1 coordinates
        {l_image.cols - 1.0f, 0.0f},    // Point 2 coordinates
        {0.0f, l_image.rows - 1.0f}     // Point 3 coordinates
    };

    Point2f l_endPoint[]
    {
        {l_image.cols - 1.0f, 0.0f},                    // Point 1 coordinates
        {0.0f, 0.0f},                                   // Point 2 coordinates
        {l_image.cols - 1.0f, l_image.rows - 1.0f}      // Point 3 coordinates
    };

    // Set the initial and end points as arrays of the second transformation
    Mat l_srcArray = (Mat_<float>(3, 2) <<
        0.0f, 0.0f,                         // Point 1 coordinates
        l_image.cols - 1.0f, 0.0f,          // Point 2 coordinates
        0.0f, l_image.rows - 1.0f           // Point 3 coordinates
        );

    Mat l_dstArray = (Mat_<float>(3, 2) <<
        0.0f, l_image.rows - 1.0f,                                  // Point 1 coordinates
        l_image.cols - 1.0f, l_image.rows - 1.0f,                   // Point 2 coordinates
        0.0f, 0.0f                                                  // Point 3 coordinates
        );

    // Calculate the transformation matrices
    Mat l_transformationMatrix1 = getAffineTransform(l_initialPoint, l_endPoint);
    Mat l_transformationMatrix2 = getAffineTransform(l_srcArray, l_dstArray);

    // Apply the transformations
    warpAffine(l_image, l_outputImageX, l_transformationMatrix1, l_outputImageX.size());
    warpAffine(l_image, l_outputImageY, l_transformationMatrix2, l_outputImageY.size());


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result X", WINDOW_NORMAL);
    cv::imshow("Result X", l_outputImageX);

    namedWindow("Result Y", WINDOW_NORMAL);
    cv::imshow("Result Y", l_outputImageY);
}

// Apply scaling to an image
void applyScaling()
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
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set the initial and end points of the first transformation
    Point2f l_initialPoint[]
    {
        {0.0f, 0.0f},                   // Point 1 coordinates
        {l_image.cols - 1.0f, 0.0f},    // Point 2 coordinates
        {0.0f, l_image.rows - 1.0f}     // Point 3 coordinates
    };

    Point2f l_endPoint[]
    {
        {-200.0f, -200.0f},                         // Point 1 coordinates
        {200.0f + l_image.cols - 1.0f, -200.0f},    // Point 2 coordinates
        {-200.0f, 200.0f + l_image.rows - 1.0f}     // Point 3 coordinates
    };

    // Set the initial and end points as arrays of the second transformation
    Mat l_srcArray = (Mat_<float>(3, 2) <<
        0.0f, 0.0f,                         // Point 1 coordinates
        l_image.cols - 1.0f, 0.0f,          // Point 2 coordinates
        0.0f, l_image.rows - 1.0f           // Point 3 coordinates
        );

    Mat l_dstArray = (Mat_<float>(3, 2) <<
        200.0f, 200.0f,                            // Point 1 coordinates
        l_image.cols - 1.0f - 200.0f, 200.0f,      // Point 2 coordinates
        200.0f, l_image.rows - 1.0f - 200.0f        // Point 3 coordinates
        );

    // Calculate the transformation matrices
    Mat l_transformationMatrix1 = getAffineTransform(l_initialPoint, l_endPoint);
    Mat l_transformationMatrix2 = getAffineTransform(l_srcArray, l_dstArray);

    // Apply the transformations
    warpAffine(l_image, l_outputImage1, l_transformationMatrix1, l_outputImage1.size());
    warpAffine(l_image, l_outputImage2, l_transformationMatrix2, l_outputImage2.size());


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result Scale Up", WINDOW_NORMAL);
    cv::imshow("Result Scale Up", l_outputImage1);

    namedWindow("Result Scale Down", WINDOW_NORMAL);
    cv::imshow("Result Scale Down", l_outputImage2);
}

// Apply scaling to an image
void applyResizing()
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

    // Create the output image matrices
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set resize properties
    constexpr double c_scaleFactorX = 0.8;
    constexpr double c_scaleFactorY = 0.8;
    const int c_upscaleSizeWidth = l_image.size().width + 400;
    const int c_upscaleSizeHeight = l_image.size().height + 400;

    // Resize the images
    resize(l_image, l_outputImage1, Size{}, c_scaleFactorX, c_scaleFactorY, INTER_AREA);
    resize(l_image, l_outputImage2, Size{ c_upscaleSizeWidth, c_upscaleSizeHeight }, 0.0, 0.0, INTER_CUBIC);

    // Display the input image
    namedWindow("Input", WINDOW_AUTOSIZE);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result Scale Down", WINDOW_AUTOSIZE);
    cv::imshow("Result Scale Down", l_outputImage1);

    namedWindow("Result Scale Up", WINDOW_AUTOSIZE);
    cv::imshow("Result Scale Up", l_outputImage2);
}

// Apply scaling to an image
void applyRotation()
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

    // Create the output image matrices
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set rotation properties
    Point2f l_rotationCenter{ l_image.cols / 2.0f, l_image.rows / 2.0f };
    constexpr double c_rotationAngleCClockwise = 45.0;
    constexpr double c_rotationAngleClockwise = -45.0;
    constexpr double c_scale = 1.0;

    // Calculate the rotation transformation matrices
    Mat l_rotationCounterClockwiseMatrix = getRotationMatrix2D(
        l_rotationCenter,
        c_rotationAngleCClockwise,
        c_scale);
    Mat l_rotationClockwiseMatrix = getRotationMatrix2D(
        l_rotationCenter,
        c_rotationAngleClockwise,
        c_scale);

    // Apply the rotation
    warpAffine(l_image, l_outputImage1, l_rotationCounterClockwiseMatrix, l_outputImage1.size());
    warpAffine(l_image, l_outputImage2, l_rotationClockwiseMatrix, l_outputImage2.size());

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result Counter Clockwise", WINDOW_NORMAL);
    cv::imshow("Result Counter Clockwise", l_outputImage1);

    namedWindow("Result Clockwise", WINDOW_NORMAL);
    cv::imshow("Result Clockwise", l_outputImage2);
}

// Apply inverse transformation to an image
void applyInverseTransformation()
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

    // Create the output image matrices
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set rotation properties
    Point2f l_rotationCenter{ l_image.cols / 2.0f, l_image.rows / 2.0f };
    constexpr double c_rotationAngleCClockwise = 45.0;
    constexpr double c_scale = 1.0;

    // Calculate the rotation transformation matrices
    Mat l_rotationCounterClockwiseMatrix = getRotationMatrix2D(
        l_rotationCenter,
        c_rotationAngleCClockwise,
        c_scale);

    // Invert the transformation matrix
    Mat l_inverseTransformation{};
    invertAffineTransform(l_rotationCounterClockwiseMatrix, l_inverseTransformation);

    // Apply the transformations
    warpAffine(l_image, l_outputImage1, l_rotationCounterClockwiseMatrix, l_outputImage1.size());
    warpAffine(l_image, l_outputImage2, l_inverseTransformation, l_outputImage2.size());

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result Counter Clockwise", WINDOW_NORMAL);
    cv::imshow("Result Counter Clockwise", l_outputImage1);

    namedWindow("Result Inverse", WINDOW_NORMAL);
    cv::imshow("Result Inverse", l_outputImage2);
}

// Apply perspective transformation to an image
void applyPerspectiveTransformation()
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
    Mat l_outputImage1;
    Mat l_outputImage2;

    // Set the initial and end points of the first transformation
    Point2f l_initialPoint[]
    {
        {0.0f, 0.0f},                                  // Point 1 coordinates
        {l_image.cols - 1.0f, 0.0f},                   // Point 2 coordinates
        {0.0f, l_image.rows - 1.0f},                   // Point 3 coordinates
        {l_image.cols - 1.0f, l_image.rows - 1.0f}     // Point 4 coordinates
    };

    Point2f l_endPoint[]
    {
        {150.0f, 150.0f},                             // Point 1 coordinates
        {l_image.cols - 1.0f - 150.0f, 150.0f},       // Point 2 coordinates
        {0.0f, l_image.rows - 1.0f},                  // Point 3 coordinates
        {l_image.cols - 1.0f, l_image.rows - 1.0f}    // Point 4 coordinates
    };

    // Set the initial and end points as arrays of the second transformation
    Mat l_srcArray = (Mat_<float>(4, 2) <<
        0.0f, 0.0f,                                    // Point 1 coordinates
        l_image.cols - 1.0f, 0.0f,                     // Point 2 coordinates
        0.0f, l_image.rows - 1.0f,                     // Point 3 coordinates
        l_image.cols - 1.0f, l_image.rows - 1.0f       // Point 4 coordinates
        );

    Mat l_dstArray = (Mat_<float>(4, 2) <<
        0.0f, 0.0f,                                                   // Point 1 coordinates
        l_image.cols - 1.0f, 0.0f,                                    // Point 2 coordinates
        150.0f, l_image.rows - 1.0f - 150.0f,                         // Point 3 coordinates
        l_image.cols - 1.0f - 150.0f, l_image.rows - 1.0f - 150.0f    // Point 4 coordinates
        );

    // Calculate the transformation matrices
    Mat l_transformationMatrix1 = getPerspectiveTransform(l_initialPoint, l_endPoint);
    Mat l_transformationMatrix2 = getPerspectiveTransform(l_srcArray, l_dstArray);

    // Apply the transformations
    warpPerspective(l_image, l_outputImage1, l_transformationMatrix1, l_outputImage1.size());
    warpPerspective(l_image, l_outputImage2, l_transformationMatrix2, l_outputImage2.size());


    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result images
    namedWindow("Result 1", WINDOW_NORMAL);
    cv::imshow("Result 1", l_outputImage1);

    namedWindow("Result 2", WINDOW_NORMAL);
    cv::imshow("Result 2", l_outputImage2);
}

// Apply remapping to an image
void applyRemapTransformation()
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

    // Create the output image and remap matrices
    Mat l_outputImage{  l_image.size(), l_image.type() };
    Mat l_remapX{ l_image.size(), CV_32FC1 };
    Mat l_remapY{ l_image.size(), CV_32FC1 };
    
    // Prepare remap matrices
    for (size_t i = 0; i < l_image.rows; ++i)
    {
        for (size_t j = 0; j < l_image.cols; ++j)
        {
            l_remapX.at<float>(i, j) = static_cast<float>(l_image.cols - (j * 0.5f));
            l_remapY.at<float>(i, j) = static_cast<float>(i);
        }
    }

    remap(l_image, l_outputImage, l_remapX, l_remapY, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    namedWindow("Result Inverse", WINDOW_NORMAL);
    cv::imshow("Result Inverse", l_outputImage);
}

int main()
{
    //applyTranslation();
    //applyReflection();
    //applyScaling();
    //applyResizing();
    //applyRotation();
    //applyInverseTransformation();
    //applyPerspectiveTransformation();
    applyRemapTransformation();

    waitKey(0);
    return 0;
}
