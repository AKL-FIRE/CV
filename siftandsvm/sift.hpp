/*
 * sift.hpp
 *
 *  Created on: 2017年3月15日
 *      Author: lcy
 */

#ifndef SIFT_HPP_
#define SIFT_HPP_
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

class mysift
{
private:
	cv::Mat src;
	cv::Ptr<cv::Feature2D> f2d;
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;
public:
	mysift();
	~mysift();
	void initial(cv::Mat &src);
	void compute();
	std::vector<cv::KeyPoint>& getKeyPoints()  {return keypoints;}
	cv::Mat& getDescriptors()  {return descriptors;}
	cv::Mat& autocalculate(cv::Mat &src);
};



#endif /* SIFT_HPP_ */
