#include "camera.h"

camera::camera()
{

}

void camera::run()
{
    //VideoCapture is for read image from video file or webcam
    cv::VideoCapture cap;
    //open camera with device number 0, if change 0 to filename string can open video file
    cap.open(0);

    //src for save image read from webcam
    cv::Mat src;
    //status for terminate the while loop
    this->status = true;

    //main while loop, read and read webcam image again
    while(this->status)
    {
        //capture image from webcam
        cap.read(src);
        //show image
        cv::imshow("src",src);
        //because the webcam FPS (frame per second) usually 30, 1000(msec)/30(FPS)~=33(msec)
        cv::waitKey(33);
    }
    //terminate the imshow window
    cv::destroyWindow("src");

    //release the webcam
    cap.release();
}

void camera::receiveStopCam(const bool &status)
{
    this->status = status;
}

