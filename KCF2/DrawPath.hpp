/*
 * DrawPath.hpp
 *
 *  Created on: 2017年4月2日
 *      Author: lcy
 */

#ifndef DRAWPATH_HPP_
#define DRAWPATH_HPP_
#include <opencv2/opencv.hpp>
class DrawPath
{
public:
	DrawPath() {};
	void Drawing(const cv::Rect &rec);
	void DrawInitial(const cv::Mat &img,const char * str);
	cv::Mat& getdrawedpath() {return drawedpath;};
private:
	std::queue<cv::Point> pots;
	cv::Mat drawedpath;
	cv::Point getCenter(const cv::Rect &rec) const;
	const char * str;
};



#endif /* DRAWPATH_HPP_ */
