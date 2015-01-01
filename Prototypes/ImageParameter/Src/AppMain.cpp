/**
 * @version     1.1.0 13-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <OpenCV/cv.h>  
#include <OpenCV/cxcore.h>
#include <OpenCV/highgui.h>
#include <ImageProcessor.h>
#include <stdlib.h>
#include <iostream>

#define KEY_ESC 27

int main(void)
{
    cv::Mat image = cv::imread("Resource/TestImage.jpg");
    
    if (image.data == 0) {
        std::cout << "Failure: couldn't load image!'" << std::endl;
    }
    else
    {
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
    }
    return EXIT_SUCCESS;
}