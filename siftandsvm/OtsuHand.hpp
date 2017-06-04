/*
 * OtsuHand.hpp
 *
 *  Created on: 2017年3月15日
 *      Author: lcy
 */

#ifndef OTSUHAND_HPP_
#define OTSUHAND_HPP_
#include <opencv2/opencv.hpp>
class OtsuHand
{
public:
	OtsuHand() {}
	cv::Mat& start(cv::Mat &src);
	cv::Mat& justRGB(cv::Mat &src);
private:
	void SkinRGB( cv::Mat &src);
	cv::Mat dst;
};



#endif /* OTSUHAND_HPP_ */
