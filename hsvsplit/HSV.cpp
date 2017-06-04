/*
 * 1.cpp
 *
 *  Created on: 2017年3月2日
 *      Author: lcy
 */

#include <opencv2/opencv.hpp>

void SkinRGB(cv::Mat &src, cv::Mat &dst);
int main()
{
	 int flag = 0;
	 cv::Mat frame,img;
	 cv::VideoCapture cap(0);
	 while(1)
	 {
		 cap >> frame;
		/* if(!flag)
		 {
			 im
			 flag++;
		 }*/
		 SkinRGB(frame,img);
		 cv::cvtColor(img,img,cv::ColorConversionCodes::COLOR_BGR2GRAY);
		 cv::threshold(img,img,255,255,cv::ThresholdTypes::THRESH_OTSU | cv::ThresholdTypes::THRESH_BINARY);
		 cv::imshow("test", img);
		 int flag = cv::waitKey(20);
		 if(flag == 'q')
			 break;
	 }

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



