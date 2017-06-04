// Fast object tracking algorithm  
// Author : zouxy  
// Date   : 2013-11-21  
// HomePage : http://blog.csdn.net/zouxy09  
// Email  : zouxy09@qq.com  
// Reference: Kaihua Zhang, et al. Fast Tracking via Spatio-Temporal Context Learning  
// HomePage : http://www4.comp.polyu.edu.hk/~cskhzhang/  
// Email: zhkhua@gmail.com   
  
#include "STCTracker.h"  
  
// Global variables  
Rect box;  
bool drawing_box = false;  
bool gotBB = false;  
  
// bounding box mouse callback  
void mouseHandler(int event, int x, int y, int flags, void *param){  
  switch( event ){  
  case CV_EVENT_MOUSEMOVE:  
    if (drawing_box){  
        box.width = x-box.x;  
        box.height = y-box.y;  
    }  
    break;  
  case CV_EVENT_LBUTTONDOWN:  
    drawing_box = true;  
    box = Rect( x, y, 0, 0 );  
    break;  
  case CV_EVENT_LBUTTONUP:  
    drawing_box = false;  
    if( box.width < 0 ){  
        box.x += box.width;  
        box.width *= -1;  
    }  
    if( box.height < 0 ){  
        box.y += box.height;  
        box.height *= -1;  
    }  
    gotBB = true;  
    break;  
  }  
}  
  
int main(int argc, char * argv[])  
{  
    VideoCapture capture;  
    capture.open(0);  
    bool fromfile = false;  
  
    if (!capture.isOpened())  
    {  
        cout << "capture device failed to open!" << endl;  
        return -1;  
    }  
    //Register mouse callback to draw the bounding box  
    cvNamedWindow("Tracker", CV_WINDOW_AUTOSIZE);  
    cvSetMouseCallback("Tracker", mouseHandler, NULL );   
  
    Mat frame;  
    capture >> frame;  
    while(!gotBB)  
    {  
        if (!fromfile)  
            capture >> frame;  
        rectangle(frame,box,Scalar(255,0,0));
        imshow("Tracker", frame);  
        if (cvWaitKey(20) == 27)  
            return 1;  
    }  
    //Remove callback  
    cvSetMouseCallback("Tracker", NULL, NULL );   
      
    STCTracker stcTracker;  
    stcTracker.init(frame, box);  
  
    int frameCount = 0;  
    while (1)  
    {  
        capture >> frame;  
        if (frame.empty())  
            return -1;  
        double t = (double)cvGetTickCount();  
        frameCount++;  
  
        // tracking  
        stcTracker.tracking(frame, box);      
  
        // show the result  
        stringstream buf;  
        buf << frameCount;  
        string num = buf.str();  
        putText(frame, num, Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3);  
        rectangle(frame, box, Scalar(0, 0, 255), 3);  
        imshow("Tracker", frame);  
  
        t = (double)cvGetTickCount() - t;  
        cout << "cost time: " << t / ((double)cvGetTickFrequency()*1000.) << endl;  
  
        if ( cvWaitKey(1) == 27 )  
            break;  
    }  
  
    return 0;  
}  