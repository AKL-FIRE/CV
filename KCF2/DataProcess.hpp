/*
 * DataProcess.hpp
 *
 *  Created on: 2017年4月2日
 *      Author: lcy
 */

#ifndef DATAPROCESS_HPP_
#define DATAPROCESS_HPP_
#include <opencv2/opencv.hpp>
#include <strstream>
#include "HOGFeature.hpp"
class DataProcess
{
public:
	DataProcess(int size) : thedataSize(size) {};
	std::vector<cv::Mat>& getTraindata() {return traindatamat;}
	cv::Mat& getsvmtraindata() {return svmtraindata;}
	void process(std::string path1,std::string path2);
	cv::Mat append(cv::Mat &Rmat);//append another class data to one.
	static cv::Mat append(cv::Mat &Lmat, cv::Mat &Rmat);
private:
	std::vector<cv::Mat> traindata;//combine the left and right hand path
	std::vector<cv::Mat> srcs;//the source images that we read
	std::vector<cv::Mat> traindatamat;//we use compute the traindata's hog features
	cv::Mat svmtraindata;//we use this to train svm,every column is a simple
	HOGFeatures hog;
	int thedataSize;
};



#endif /* DATAPROCESS_HPP_ */
