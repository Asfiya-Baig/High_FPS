#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>

using namespace std;
using namespace cv;
Mat image;
char fname[100];
int main()
{

    char key;
    VideoCapture capture(CV_CAP_DSHOW + 1);	//Opens the camera of the device connected
    capture.set(CV_CAP_PROP_EXPOSURE,-7);
    capture.set(CV_CAP_PROP_FPS,120);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,640);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    double f= capture.get(CV_CAP_PROP_FPS);
    cout<<f<<"  "<<endl;
capture>>image;			//Extract a frame and store in image matrix.
int framewidth=image.cols;
int frameheight=image.rows;

strcpy(fname, "C://Users//Asfiya Baig//Documents//f//video1.avi");
/*Define VideoiWriter object for storing the video*/
  VideoWriter video1(fname,CV_FOURCC('M','J','P','G'),f,cvSize(framewidth, frameheight));  //CV_FOURCC('M','J','P','G') is a motion-jpeg codec



while(1)
{
    capture>>image;
namedWindow("Video",WINDOW_NORMAL);
imshow("Video",image);
video1<<image;
key = waitKey(100); 	//Capture Keyboard stroke
if (char(key) == 27)
	{
	        break; 		//If you hit ESC key loop will break and code will terminate

	}
}
return 0;
}
