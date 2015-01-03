/**
 * ImageParameter - Application Main.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/AppMain.cpp
 * @version     1.2.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <OpenCV/cv.h>  
#include <OpenCV/cxcore.h>
#include <OpenCV/highgui.h>
#include <ImageProcessor.h>
#include <cstdlib>
#include <iostream>

#define KEY_ESC 27

int main(const int argc, char** argv)
{
    cv::Mat image;
    
    if (argc >= 2) {
        image = cv::imread(argv[1]);
    }
    
    if (image.data == 0)
    {
        std::cout << "Failure: couldn't load image! created a static dummy image instead!" << std::endl;
        
        image = cv::Mat::zeros(10, 10, CV_8UC3);
        
        // fill half of the image with blue color
        cv::rectangle(image, cv::Point(0, 5), cv::Point(10, 10), cv::Scalar(255, 0, 0), CV_FILLED);
        
        cv::rectangle(image, cv::Point(0, 0), cv::Point(5, 10), cv::Scalar(0, 255, 0), CV_FILLED, 4);
    }
    
    cv::namedWindow("Debug Output", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("Debug Output: Bottom Part", CV_WINDOW_AUTOSIZE);
    
    ImageProcessor* processor = new ImageProcessor();
    
    // determine image format
    ImageFormat format = processor->getImageFormat(image);
    
    if (format == ImageFormat_Landscape) {
        std::cout << "format: landscape" << std::endl;
    }
    else if (format == ImageFormat_Portrait) {
        std::cout << "format: portrait" << std::endl;
    }
    else {
        std::cout << "format: square" << std::endl;
    }
    
    // what kind of image?
    std::cout << "Image type: " << image.type() << std::endl;
    
    // split image in two
    cv::Mat imagePartBottom;
    
    processor->splitImage(ProcessorFlags_Height, image, NULL, &imagePartBottom);
    
    std::cout << "amount of water: " << processor->getAmountOfWater(imagePartBottom) << std::endl;
    
    if (processor != NULL)
    {
        delete processor;
        processor = NULL;
    }
    
    cv::imshow("Debug Output", image);
    cv::imshow("Debug Output: Bottom Part", imagePartBottom);
    
    // to prevent that the application terminates
    // after the image appeared we'll wait till the
    // user hits the ESC key
    do {
    } while (cv::waitKey(50) != KEY_ESC);
    
    cvDestroyAllWindows();
    
    return EXIT_SUCCESS;
}