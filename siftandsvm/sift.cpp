/*
 * sift.cpp
 *
 *  Created on: 2017年3月15日
 *      Author: lcy
 */
#include "sift.hpp"

mysift::mysift()
{}

mysift::~mysift()
{}

void mysift::initial(cv::Mat &src)
{
	if(src.empty())
		return;
	this->src = src;
	f2d = cv::xfeatures2d::SIFT::create();
}

void mysift::compute()
{
	f2d->detect(src,keypoints);
	f2d->compute(src,keypoints,descriptors);
}

cv::Mat& mysift::autocalculate(cv::Mat &src)
{
	initial(src);
	compute();
	return descriptors;
}

