/*
 * HOGFeature.hpp
 *
 *  Created on: 2017年3月26日
 *      Author: lcy
 */

#ifndef HOGFEATURE_HPP_
#define HOGFEATURE_HPP_
#include <opencv2/opencv.hpp>
class HOGFeatures
{
public:
	HOGFeatures(cv::Size winsize = cv::Size(64, 48), cv::Size blocksize =
			cv::Size(32, 32), cv::Size blockstep = cv::Size(8, 8),
			cv::Size cellsize = cv::Size(16, 16),int bins = 9);
	~HOGFeatures() {};
	void HOGCompute(cv::Mat &src,std::vector<float>& descriptor = descriptors,cv::Size winstep = cv::Size(64,48),cv::Size padding = cv::Size(0,0));
private:
	cv::Ptr<cv::HOGDescriptor> hog;
	static std::vector<float> descriptors;
};



#endif /* HOGFEATURE_HPP_ */
