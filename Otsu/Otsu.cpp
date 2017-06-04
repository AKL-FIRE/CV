/*
 * Ostu.cpp
 *
 *  Created on: 2017年3月5日
 *      Author: lcy
 */


#include <opencv2/opencv.hpp>
#include <iostream>

int Otsu(const cv::Mat src);

int main(int argc, char **argv)
{
	cv::VideoCapture cap(0);
	cv::Mat frame,dst;
	int mythreshold;
	while(1)
	{
		cap >> frame;
		int flag = cv::waitKey(10);
		if(flag == 'q')
			break;
		//mythreshold = Otsu(frame);
		cv::cvtColor(frame,dst,cv::ColorConversionCodes::COLOR_BGR2GRAY);
		cv::threshold(dst,dst,255,255,cv::ThresholdTypes::THRESH_OTSU | cv::ThresholdTypes::THRESH_BINARY);
		cv::imshow("result",dst);
	}
}

int Otsu( cv::Mat src)
{
	cv::cvtColor(src,src,cv::ColorConversionCodes::COLOR_BGR2GRAY);
	float histogram[256] = {0};
	for(int i = 0; i < src.rows; i++)
	{
		unsigned char *pdata = src.ptr<uchar>(i);
		for(int j = 0; j < src.cols; j++)
		{
			histogram[*pdata++]++;
		}
	}
	float totalaverage = 0;
	int totalpiexl = src.cols * src.rows;
	for(int i = 0;i < 256; i++)
	{
		histogram[i] = (float)histogram[i] / (float)totalpiexl;
		totalaverage += i * histogram[i];
	}
	float PA = 0;
	float PB =0;
	float Aaverage = 0;
	float Baverage = 0;
	double variance = 0;
	double maxvariance = 0;
	int mythreshold = 0;
	for(int i = 0; i < 255; i++)
	{
		PA += histogram[i];
		PB = 1 - PA;
		Aaverage += i * histogram[i];
		Baverage = totalaverage - Aaverage;

		variance = PA * (Aaverage - totalaverage) * (Aaverage - totalaverage) + PB * (Baverage - totalaverage) * (Baverage - totalaverage);

		if(variance > maxvariance)
		{
			maxvariance = variance;
			mythreshold = i;
		}
	}
	
	
	return mythreshold;
}