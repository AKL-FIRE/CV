/*
 * Bow.cpp
 *
 *  Created on: 2017年4月16日
 *      Author: lcy
 */

#include "Bow.hpp"

void BowFeature::initBowTrainer(int clusterCount)
{
	bowTrainer = new cv::BOWKMeansTrainer(clusterCount);
}

void BowFeature::initBowImgExtractor()
{
	descExtractor = cv::xfeatures2d::SIFT::create();
	descMatcher = cv::DescriptorMatcher::create("FlannBased");
	bowImgExtractor = new cv::BOWImgDescriptorExtractor(descExtractor, descMatcher);
	if(dictionary.empty())
	{
		cv::FileStorage fs("dictionary.yml",cv::FileStorage::READ);
		fs["vocabulary"] >> dictionary;
		fs.release();
	}
	if(dictionary.empty())
	{
		std::cout << "read file failed.";
		exit(-1);
	}
	bowImgExtractor->setVocabulary(dictionary);
}

void BowFeature::FormVisualWords(int clusterCount, cv::Mat &allFeatures)
{
	if(dictionary.empty())
	{
		initBowTrainer(clusterCount);
	}
	dictionary = bowTrainer->cluster(allFeatures);
	cv::FileStorage fs("dictionary.yml", cv::FileStorage::WRITE);
	fs << "vocabulary" << dictionary;
	fs.release();
	std::cout << dictionary.size();
}


cv::Mat BowFeature::ExtractorFeatureByBow(cv::Mat &img, std::vector<cv::KeyPoint>& keypoints)
{
	initBowImgExtractor();
	cv::Mat descriptors;
	//cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();
	//sift->detectAndCompute(img, cv::noArray(), keypoints, descriptors);
	bowImgExtractor->compute(img,keypoints,descriptors);
	return descriptors;
}

