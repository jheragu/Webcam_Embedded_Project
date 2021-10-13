#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "include/canny.h"

using namespace cv;
using namespace std;

canny::canny (int lowThreshold, int max_lowThreshold, int ratio) {
    int kernel_size{1};
    Mat src;
    Mat src_gray;
    Mat dst;
    Mat detected_edges;
}

Mat canny::CannyThreshold(int, void*)
{
    cerr << "Enters CannyThreshhold" << endl;
    // Blur the image with a filter of kernel size 3
    blur(src_gray, detected_edges, Size(3,3));
    
    // kernel_size -> Size of the Sobel Kernel
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio);
    
    // Create a Matrix with all zeros (black)
    dst = Scalar::all(0);
    
    // areas identified as edges copied to a black background
    src.copyTo(dst, detected_edges);
  
    return dst;
}

Mat canny::prepare_canny(string file){

    cerr << "Calls calc_canny()" << endl;
    // Open image
    src = imread(file , IMREAD_COLOR); // Load an image
    if(src.empty()){
        cout << "Could not open or find the image!\n" << endl;
    }
    
    // Create matrix with the same size as the image
    dst.create(src.size(), src.type());
    
    // Grayscale
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    
    Mat dst = CannyThreshold(0, 0);

    return dst;
}
