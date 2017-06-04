/*
 * KalmanFilter.cpp
 *
 *  Created on: 2017年3月16日
 *      Author: lcy
 */

#include "KalmanFilter.hpp"

Kalman::Kalman()
{
	kalman = new cv::KalmanFilter();
}


Kalman::~Kalman()
{
}


void Kalman::init(int dynamParams,int measureParams,int controlParams)
{
	if(kalman.empty())
		return;
	kalman->init(dynamParams,measureParams,controlParams);
	setallparams();
}

const cv::Mat& Kalman::predict()
{
	return kalman->predict();
}

const cv::Mat& Kalman::correct(const cv::Mat& measurement)
{
	return kalman->correct(measurement);
}

void Kalman::setallparams()
{
	cv::Mat state(4,1,CV_32FC1);
	cv::Mat processNoise(4,1,CV_32F);
	cv::Mat measurement = cv::Mat::zeros(2,1,CV_32F);

	cv::randn(state,cv::Scalar::all(0),cv::Scalar::all(0.1));
	kalman->transitionMatrix = (cv::Mat_<float>(4,4)<<
	1,0,1,0,
	0,1,0,1,
	0,0,1,0,
	0,0,0,1);

	cv::setIdentity(kalman->measurementMatrix);
	cv::setIdentity(kalman->processNoiseCov,cv::Scalar::all(1e-5));
	cv::setIdentity(kalman->measurementNoiseCov,cv::Scalar::all(1e-5));
	cv::setIdentity(kalman->errorCovPost,cv::Scalar::all(1));

	//cv::randn(kalman->statePost,cv::Scalar::all(0),cv::Scalar::all(0.1));

}

cv::Ptr<cv::KalmanFilter>& Kalman::getkalman()
{
	return kalman;
}
