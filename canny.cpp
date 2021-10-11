#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "include/canny.h"

using namespace cv;
using namespace std;

canny::canny () {
    int lowThreshold{0};
    int max_lowThreshold{100};
    int ratio{3};
    int kernel_size{3};
    char* window_name{"Edge Map"};
    Mat src;
    Mat src_gray;
    Mat dst;
    Mat detected_edges;
}

Mat canny::CannyThreshold(int, void*)
{
    blur(src_gray, detected_edges, Size(3,3));
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
    
    return dst;
}

Mat canny::calc_canny(string file){

    src = imread( file , IMREAD_COLOR ); // Load an image
    if( src.empty() ){
        cout << "Could not open or find the image!\n" << endl;
    }

    dst.create( src.size(), src.type() );
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    //namedWindow( window_name, WINDOW_AUTOSIZE );
    //createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
    Mat dst = CannyThreshold(3, 0);

    return dst;
}
