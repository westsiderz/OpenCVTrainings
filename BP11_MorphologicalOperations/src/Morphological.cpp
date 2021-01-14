#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

// Applies the Opening morphological operation 
void applyOpening()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbolNoisy.jpg" };

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
    
    // Creating the structuring element for the morphological operation
    int l_openingSize = 9;
    Mat l_openingElement = getStructuringElement( MORPH_RECT,
                       Size( 2*l_openingSize + 1, 2*l_openingSize+1 ),
                       Point( l_openingSize, l_openingSize ) );
      
    // Applying the Opening Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_OPEN, l_openingElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Applies the Closing morphological operation 
void applyClosing()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbolBroken.jpg" };

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
    
    // Creating the structuring element for the morphological operation
    int l_closingSize = 5;
    Mat l_closingElement = getStructuringElement( MORPH_RECT,
                       Size( 2*l_closingSize + 1, 2*l_closingSize+1 ),
                       Point( l_closingSize, l_closingSize ) );
      
    // Applying the Closing Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_CLOSE, l_closingElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Applies the morphological Gradient operation 
void applyGradient()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/loveSymbol.jpg" };

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
    
    // Creating the structuring element for the morphological operation
    int l_gradientSize = 5;
    Mat l_gradientElement = getStructuringElement( MORPH_RECT,
                       Size( 2*l_gradientSize + 1, 2*l_gradientSize+1 ),
                       Point( l_gradientSize, l_gradientSize ) );
      
    // Applying the Gradient Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_GRADIENT, l_gradientElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Applies the Top hat morphological operation 
void applyTophat()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/kiss.jpg" };

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
    
    // Creating the structuring element for the morphological operation
    int l_topHatSize = 9;
    Mat l_topHatElement = getStructuringElement( MORPH_RECT,
                       Size( 2*l_topHatSize + 1, 2*l_topHatSize+1 ),
                       Point( l_topHatSize, l_topHatSize ) );
      
    // Applying the Top hat Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_TOPHAT, l_topHatElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}

// Applies the Black hat morphological operation 
void applyBlackhat()
{
    // Path to the input image
    std::string l_pathToInputImage{ "../Resources/kiss.jpg" };

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
    
    // Creating the structuring element for the morphological operation
    int l_blackHatSize = 9;
    Mat l_blackHatElement = getStructuringElement( MORPH_RECT,
                       Size( 2*l_blackHatSize + 1, 2*l_blackHatSize+1 ),
                       Point( l_blackHatSize, l_blackHatSize ) );
      
    // Applying the Black hat Morphological operation               
    morphologyEx( l_image, l_outputImage, MORPH_BLACKHAT, l_blackHatElement );
		 

    // Display the input image
    namedWindow("Input", WINDOW_NORMAL);
    cv::imshow("Input", l_image);

    // Display the result image
    namedWindow("Result", WINDOW_NORMAL);
    cv::imshow("Result", l_outputImage);
}


int main()
{
    //applyOpening();
    //applyClosing();
    //applyGradient();
    //applyTophat();
    applyBlackhat();

    waitKey(0);
    return 0;
}
