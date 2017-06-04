/*
 * sift1.cpp
 *
 *  Created on: 2017年2月27日
 *      Author: lcy
 */

#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>
void SkinRGB(cv::Mat &src, cv::Mat &dst);
int main(int argc, char** argv)
{
	cv::Mat img,img1,img2;
	cv::VideoCapture cap(0);
	int flags = 1;
	while(1)
	{
		cap >> img;
		cv::imshow("img",img);
		int flags = cv::waitKey(20);
		if(flags == 's')
		{
			//img.copyTo(img1);
			SkinRGB(img,img1);
			flags++;
			break;
		}
	}
	while(1)
		{
			cap >> img;
			cv::imshow("img",img);
			int flags = cv::waitKey(20);
			if(flags == 's')
			{
				SkinRGB(img,img2);
				cap.release();
				break;
			}
		}
	std::vector<cv::KeyPoint> keypoints1;
	std::vector<cv::KeyPoint> keypoints2;
	cv::Ptr<cv::FeatureDetector> detector = cv::xfeatures2d::SURF::create(1500);
	detector->detect(img1,keypoints1);
	detector->detect(img2,keypoints2);
	cv::Mat descriptor1,descriptor2;
	detector->compute(img1,keypoints1,descriptor1);
	detector->compute(img2,keypoints2,descriptor2);

	cv::BFMatcher matcher(cv::NORM_L2,true);
	std::vector<cv::DMatch> matches;
	matcher.match(descriptor1,descriptor2,matches);
	cv::Mat match_img;
	cv::drawMatches(img1,keypoints1,img2,keypoints2,matches,match_img,cv::Scalar(255,255,255),cv::Scalar(255,0,0));
	cv::imshow("result",match_img);
	cv::waitKey(0);
	return 0;
}

void SkinRGB(cv::Mat &src, cv::Mat &dst)
{
	dst = cv::Mat::zeros(src.size(),src.type());
	for(int j = 0; j < src.rows; j++)
	{
		uchar* data = src.ptr<uchar>(j);
		uchar* pdst = dst.ptr<uchar>(j);

		for(int i = 0; i < src.cols ; i++)
		{
			if((data[i * 3 + 2] > 95 && data[i * 3 + 1] > 40 && data[i * 3] > 20 && (data[i * 3 + 2] - data[i * 3 + 1] > 15) &&
					(data[i * 3 + 2] - data[i * 3] > 15)) || (data[i * 3 + 2] > 200 && data[i * 3 + 1] > 210 && data[i * 3] > 170 &&
					(data[i * 3 + 2] - data[i * 3] <= 15) && data[i * 3 + 2] > data[i * 3] && data[i * 3 + 1] > data[i * 3]))
			{
				pdst[i * 3] = data[i * 3];
				pdst[i * 3 + 1] = data[i * 3 + 1];
				pdst[i * 3 + 2] = data[i * 3 + 2];
			}
		}
	}
}
