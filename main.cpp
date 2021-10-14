#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "include/canny.h"
#include <future>
//#include <curl/curl.h>

using namespace cv;
using namespace std;


void call_bash(string img_canny)
{
    string bash = "bash azcli_upload_blob.sh " + img_canny;
    
    /*
    stringstream string_to_divide(img_canny);
    char delimeter = '/';
    string substring;
    vector<std::string> vec_substrings {};
    //Divide the string pro blank space
    while(getline(string_to_divide, substring, delimeter)){
        //Separates path and file
        vec_substrings.push_back(substring);
    }

    cout << "Upload " <<  vec_substrings[2];
    const char* command = vec_substrings[2].c_str();
    */
    const char* command = bash.c_str();
    system(command);

    cout << "***** Frame successfully uploaded to Azure *****" << endl;
    
}

int main(int, char**)
{
    Mat frame;
    cout << "***** Init Webcam Capture *****" << endl;
    VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    
    // open selected camera using selected API
    cap.open(deviceID, apiID);

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 250); // valueX = your wanted width
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 250); // valueY = your wanted heigth
    
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    //timer
    time_t timer;
    time_t timer_1;
    
    //--- GRAB AND WRITE LOOP
    cout << "Start saving frames" << endl;
    
    //Time now
    time(&timer);
    cout << timer << "\n";  

    for (;;)
    {   
        auto i = 0; //Avoid several frames being stored --> loop is executed faster than 1s
        while(((time(&timer_1) - timer) % 2) == 0){
            
            //cout << timer_1 << "\n"; 
            // wait for a new frame from camera and store it into 'frame'
            cap.read(frame);
            // check if we succeeded
            if (frame.empty()) {
                cerr << "ERROR! blank frame grabbed\n";
                break;
            }
            // No window will be shown -> loop too quick 
            imshow("Live Camera Feed", frame);

            if(i == 0){
                cout << "***** New Frame has been captured *****" << endl;
                //Pretty Time Print
                cout << std::asctime(std::localtime(&timer));

                long guid = rand() % 1000;
                string file = "./frames/frame_" + to_string(guid) + ".png";
                imwrite(file, frame);

                canny cn(60, 100, 3);
                cout << "About to start calculating edges with Canny Detector..." << endl;
                Mat mat_canny = cn.prepare_canny(file);

                string img_canny = "./frames_canny/frame_" + to_string(guid) + ".png";
                imwrite(img_canny, mat_canny);

                //Call the bash script to upload the image to Azure Blob Storage
                future<void> temp = async (call_bash, img_canny);
            }
            i++; //avoid several repetitions of grabbing a frame
        }
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}