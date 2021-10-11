//#ifndef CANNY_H
//#define CANNY_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

class canny{

    public:

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

        // Constructor
        canny();

        Mat CannyThreshold(int, void*);

        Mat calc_canny(string file);
};

//#endif // CANNY_H