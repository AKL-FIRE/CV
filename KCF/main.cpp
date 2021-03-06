/*
 * main.cpp
 *
 *  Created on: 2017年3月16日
 *      Author: lcy
 */
#include "kcftracker.hpp"


int main()
{
	cv::Mat frame1;
	cv::VideoCapture cap(0);
	std::auto_ptr<KCFTracker> kcf1(new KCFTracker(true,true,false,false));
	std::auto_ptr<KCFTracker> kcf2(new KCFTracker(true,true,false,false));
	cv::Rect rect1(cv::Point(150,200),cv::Point(250,300));
	cv::Rect rect2(cv::Point(450,200),cv::Point(550,300));
	while(1)
	{
		cap >> frame1;
		cv::rectangle(frame1,cv::Point(150,200),cv::Point(250,300),cv::Scalar(255,0,0),1);
		cv::rectangle(frame1,cv::Point(450,200),cv::Point(550,300),cv::Scalar(0,255,0),1);
		int flag = cv::waitKey(20);
		cv::imshow("123",frame1);
		if(flag == 'q')
		{
			kcf1->init(rect1,frame1);
			kcf2->init(rect2,frame1);
			break;
		}
	}

	while(1)
	{
		cap >> frame1;
		rect1 = kcf1->update(frame1);
		rect2 = kcf2->update(frame1);
		kcf1->setdistance(rect1,rect2);
		kcf2->setdistance(rect1,rect2);
		cv::rectangle(frame1,rect1,cv::Scalar(255,0,0),1);
		cv::rectangle(frame1,rect2,cv::Scalar(0,255,0),1);
		//cv::rectangle(frame,kcf1->temp,cv::Scalar(0,255,0),1);
		int flag = cv::waitKey(20);
		cv::imshow("123",frame1);
		if(flag == 'q')
		{
			break;
		}
	}

}

