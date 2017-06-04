/*
 * test.cpp
 *
 *  Created on: 2017年3月16日
 *      Author: lcy
 */

#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

const int winWidth = 800;
const int winHeight = 600;

Point mousePosition = Point(winWidth>>1,winHeight>>1);

void mouseEvent(int event,int x,int y,int flags, void* param)
{
	if(event == CV_EVENT_MOUSEMOVE)
	{
		mousePosition = Point(x,y);
	}
}

int main()
{
	const int stateNum = 4;//The number of states
	const int measureNum = 2;//

	KalmanFilter KF(stateNum,measureNum,0);
	Mat state(stateNum,1,CV_32FC1);
	Mat processNoise(stateNum,1,CV_32F);
	Mat measurement = Mat::zeros(measureNum,1,CV_32F);

	randn(state,Scalar::all(0),Scalar::all(0.1));
	KF.transitionMatrix = (Mat_<float>(4,4) <<
	1,0,1,0,
	0,1,0,1,
	0,0,1,0,
	0,0,0,1);

	setIdentity(KF.measurementMatrix);

	setIdentity(KF.processNoiseCov,Scalar::all(1e-5));

	setIdentity(KF.measurementNoiseCov,Scalar::all(1e-1));

	setIdentity(KF.errorCovPost,Scalar::all(1));

	randn(KF.statePost,Scalar::all(0),Scalar::all(0.1));
	Mat showImg(winWidth,winHeight,CV_8UC3);

	for(;;)
	{
		setMouseCallback("Kalman",mouseEvent);
		showImg.setTo(0);

		Point statePt = Point((int)KF.statePost.at<float>(0),(int)KF.statePost.at<float>(1));

		Mat prediction = KF.predict();
		Point predictPt = Point((int)prediction.at<float>(0),(int)prediction.at<float>(1));

		measurement.at<float>(0) = (float)mousePosition.x;
		measurement.at<float>(1) = (float)mousePosition.y;

		KF.correct(measurement);

		circle(showImg,statePt,5,CV_RGB(255,0,0),1);
		circle(showImg,predictPt,5,CV_RGB(0,255,0),1);
		circle(showImg,mousePosition,5,CV_RGB(0,0,255),1);

		putText(showImg,"Red:Former Point",Point(10,30),FONT_HERSHEY_SIMPLEX,1,Scalar::all(255));
		putText(showImg,"Green:Predict Point",Point(10,60),FONT_HERSHEY_SIMPLEX,1,Scalar::all(255));
		putText(showImg,"Blue:Ture Point",Point(10,90),FONT_HERSHEY_SIMPLEX,1,Scalar::all(255));

		imshow("Kalman",showImg);
		int key = waitKey(3);
		if(key=='q')
			break;
	}
}



