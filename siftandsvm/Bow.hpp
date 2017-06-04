/*
 * BOW.hpp
 *
 *  Created on: 2017年4月16日
 *      Author: lcy
 */

#ifndef BOW_HPP_
#define BOW_HPP_
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>


class BowFeature
{
public:
	BowFeature() {};
	~BowFeature() {};
	void FormVisualWords(int clusterCount, cv::Mat &allFeatures);//allFeatrues means a single mat which consist of a number of sift descriptors,
																//The function will produce a document called "dictionary.yml" which store the (vocabulary) mat
	cv::Mat ExtractorFeatureByBow(cv::Mat &img, std::vector<cv::KeyPoint>& keypoints);
private:
	cv::Ptr<cv::BOWKMeansTrainer> bowTrainer;  //Use this to construct bags of words
	cv::Ptr<cv::BOWImgDescriptorExtractor> bowImgExtractor; //Use this to extractor the descriptions
	cv::Ptr<cv::xfeatures2d::SiftDescriptorExtractor> descExtractor;
	cv::Ptr<cv::DescriptorMatcher> descMatcher;

	cv::Mat dictionary; //Which means the BowTrainer use data to generate the result

	void initBowTrainer(int clusterCount); //clusterCount is the number of cluster
	void initBowImgExtractor();
};


#endif /* BOW_HPP_ */
