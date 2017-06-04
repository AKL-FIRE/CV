#pragma once
#include <opencv2/opencv.hpp>

static cv::Point getcenter(cv::Rect &rec)
{
	cv::Point pointx1 = rec.tl();
	cv::Point pointcenter = cv::Point(pointx1.x + rec.height / 2, pointx1.y + rec.width / 2);
	return pointcenter;
}

static cv::Mat drawinitial(const cv::Mat &img)
{
	cv::namedWindow("cut");
	cv::Mat picture(img.rows, img.cols, CV_8UC1, cv::Scalar(0));
	return picture;
}
