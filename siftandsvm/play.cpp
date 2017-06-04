/*
 * play.cpp
 *
 *  Created on: 2017年4月16日
 *      Author: lcy
 */


#include "sift.hpp"
#include "OtsuHand.hpp"
#include <iostream>
#include "SVMClassifier.h"
#include "Bow.hpp"
#include <string>
#include <ctime>
int AmIWin(int a,int b);
int main(int argc, char** argv)
{

	cv::Mat frame,result,descriptors,descripters_all,roi;
	cv::VideoCapture cap(0);
	OtsuHand a;
	BowFeature bow;
	SVMClassifier svm;
	svm.LoadModel("svm.xml");
	int flag;
	for(int i = 0;i < 3; i++)
	{
		while(1)
		{
			cap >> frame;
			flag = cv::waitKey(20);
			cv::rectangle(frame,cv::Point(350,200),cv::Point(500,350),cv::Scalar(255,0,0),1);
			if(flag == 'q')
			{
				break;
			}
			cv::Mat temp = frame(cv::Rect(350,200,150,150));
			temp.copyTo(roi);
			result = a.justRGB(roi);
			cv::imshow("2",result);
		}
		mysift sift1;
		sift1.autocalculate(result);
		descriptors = bow.ExtractorFeatureByBow(result,sift1.getKeyPoints());
		srand((unsigned)time(0));
		int ran_num = rand() % 3 + 1;// 1 means hammer ,2 means scissors, 3 means cloth.
		switch(ran_num)
		{
		case 1:
			std::cout << "The computer uses hammer\n";
			break;
		case 2:
			std::cout << "The computer uses scissors\n";
			break;
		case 3:
			std::cout << "The computer uses cloth\n";
			break;
		}
		switch((int)svm.Predict(descriptors))
		{
		case 1:
			std::cout << "You use hammer\n";
			break;
		case 2:
			std::cout << "You use scissors\n";
			break;
		case 3:
			std::cout << "You use cloth\n";
			break;
		}
		switch(AmIWin(svm.Predict(descriptors),ran_num))
		{
		case -1:
			std::cout << "You lose\n";
			break;
		case 0:
			std::cout << "Not bad, both you win\n";
			break;
		case 1:
			std::cout << "Congratulations!,you win the game\n";
		}
		cv::imshow("2",result);
		cv::waitKey(7000);
		flag = 0;
	}
	cap.release();
	std::cout << "done.";
}

//-1 lose, 0 both win, 1 win
int AmIWin(int a,int b)
{
	if((a == 1 && b == 1) || (a == 2 && b == 2) || (a == 3 && b == 3))
		return 0;
	if((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
		return 1;
	else
		return -1;
}


