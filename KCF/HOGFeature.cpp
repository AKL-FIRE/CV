/*
 * HOGFeature.cpp
 *
 *  Created on: 2017年3月26日
 *      Author: lcy
 */
#include "HOGFeature.hpp"

HOGFeatures::HOGFeatures(cv::Size winsize, cv::Size blocksize , cv::Size blockstep, cv::Size cellsize,int bins)
{
	hog = new cv::HOGDescriptor(winsize,blocksize,blockstep,cellsize,bins);
}

void HOGFeatures::HOGCompute(cv::Mat &src,std::vector<float>& descriptor,cv::Size winstep,cv::Size padding)
{
	hog->compute(src,descriptor,winstep,padding);
}
