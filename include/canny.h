#ifndef CANNY_H
#define CANNY_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

class canny{

    public:
        // Constructor
        canny(int, int, int);

        Mat prepare_canny(string file);

    protected:
        // Data Members
        int lowThreshold;
        int max_lowThreshold;
        int ratio;
        int kernel_size;
        char* window_name;
        Mat src;
        Mat src_gray;
        Mat dst;
        Mat detected_edges;

        Mat CannyThreshold(int, void*);

        
};

#endif // CANNY_H