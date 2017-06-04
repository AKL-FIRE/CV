/*
 * OtsuHand.cpp
 *
 *  Created on: 2017年3月15日
 *      Author: lcy
 */
#include "OtsuHand.hpp"
cv::Mat& OtsuHand::start(cv::Mat &src)
{
	SkinRGB(src);
	cv::cvtColor(dst,dst,cv::COLOR_BGR2GRAY);
	cv::threshold(dst,dst,255,255,cv::THRESH_OTSU);
	return dst;
}

cv::Mat& OtsuHand::justRGB(cv::Mat& src)
{
	SkinRGB(src);
	return dst;
}

void OtsuHand::SkinRGB( cv::Mat &src)
{
	dst = cv::Mat::zeros(src.size(),src.type());
		for(int j = 0; j < src.rows; j++)
		{
			uchar* data = src.ptr<uchar>(j);
			uchar* pdst = dst.ptr<uchar>(j);

			for(int i = 0; i < src.cols ; i++)
			{
				if((data[i * 3 + 2] > 95 && data[i * 3 + 1] > 40 && data[i * 3] > 20 && (data[i * 3 + 2] - data[i * 3] > 15) &&
						(data[i * 3 + 2] - data[i * 3 + 1] > 15)) || (data[i * 3 + 2] > 200 && data[i * 3 + 1] > 210 && data[i * 3] > 170 &&
						abs((data[i * 3 + 2] - data[i * 3]) <= 15) && data[i * 3 + 2] > data[i * 3] && data[i * 3 + 1] > data[i * 3]))
				{
					pdst[i * 3] = data[i * 3];
					pdst[i * 3 + 1] = data[i * 3 + 1];
					pdst[i * 3 + 2] = data[i * 3 + 2];
				}
			}
		}
}


