/**
 * @version     1.1.0 29-Dec-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <OpenCV/cv.h>
#include <OpenCV/cxcore.h>
#include <OpenCV/highgui.h>
#include <stdlib.h>

#define SAMPLE_IMAGES 5
#define KEY_ESC 27

void generateImage(cv::Mat* image)
{
    image->create(100, 100, CV_8UC1);
}

int main(void)
{
    cv::Mat sampleImage[SAMPLE_IMAGES];

    for (unsigned int i=0; i < SAMPLE_IMAGES; ++i)
    {
        char buffer[100];
        
        generateImage(&sampleImage[i]);
        
        sprintf(buffer, "Sample Image %d#", i);
        
        cv::namedWindow(buffer, CV_WINDOW_AUTOSIZE);
        cvMoveWindow(buffer, 20, 50 * (i + 1) + (100 * i));
        cv::imshow(buffer, sampleImage[i]);
    }
    
    // to prevent that the application terminates
    // after the image appeared we'll wait till the
    // user hits the ESC key
    do {
    } while (cv::waitKey(50) != KEY_ESC);
    
    cvDestroyAllWindows();

    return EXIT_SUCCESS;
}