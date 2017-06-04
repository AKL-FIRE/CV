/*
 * DrawPath.cpp
 *
 *  Created on: 2017年4月2日
 *      Author: lcy
 */

#include "DrawPath.hpp"

void DrawPath::Drawing(const cv::Rect &rec)
{
	if (pots.size() == 2)
	{
		cv::line(drawedpath, pots.front(), pots.back(), cv::Scalar(255), 35);
		pots.pop();
	}
	pots.push(getCenter(rec));
	cv::imshow(str,drawedpath);
}

cv::Point DrawPath::getCenter(const cv::Rect &rec) const
{
	return cv::Point(rec.x + rec.width / 2,rec.y + rec.height / 2);
}

void DrawPath::DrawInitial(const cv::Mat &img,const char * str)
{
	this->str = str;
	cv::namedWindow(this->str);
	drawedpath = cv::Mat(img.rows, img.cols, CV_8UC1, cv::Scalar(0));
}

