/*
 * KalmanFilter.hpp
 *
 *  Created on: 2017年3月16日
 *      Author: lcy
 */

#ifndef KALMANFILTER_HPP_
#define KALMANFILTER_HPP_
#include <opencv2/video/tracking.hpp>
class Kalman
{
public:
	Kalman();
	~Kalman();
	void init(int dynamParams,int measureParams,int controlParams=0);
	const cv::Mat& predict();
	const cv::Mat& correct(const cv::Mat& measurement);
	cv::Ptr<cv::KalmanFilter>& getkalman() ;
private:
	cv::Ptr<cv::KalmanFilter> kalman;
	void setallparams();
};



#endif /* KALMANFILTER_HPP_ */
