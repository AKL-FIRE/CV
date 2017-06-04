/*
 * DataProcess.cpp
 *
 *  Created on: 2017年4月2日
 *      Author: lcy
 */

#include "DataProcess.hpp"

void DataProcess::process(std::string path1,std::string path2)
{
	for(int i = 1;i <= thedataSize ;i++)
		{
			std::strstream ss;
			std::string str1(path1),str2;
			ss << i;
			ss >> str2;
			str2.append(".jpg");
			str1.append(str2);
			srcs.push_back(cv::imread(str1,cv::IMREAD_GRAYSCALE));
		}
		for(int i = 1;i <= thedataSize ;i++)
		{
			std::strstream ss;
			std::string str1(path2),str2;
			ss << i;
			ss >> str2;
			str2.append(".jpg");
			str1.append(str2);
			srcs.push_back(cv::imread(str1,cv::IMREAD_GRAYSCALE));
		}
		if(srcs.empty())
		{
			std::cout << "Image read failed.";
			exit(-1);
		}
		//for(auto &c : srcs)
			//cv::cvtColor(c,c,cv::COLOR_BGR2GRAY);
		for(int i = 0; i < thedataSize; i++)
		{
			cv::Mat temp(srcs[0].rows * 2,srcs[0].cols,srcs[0].type());
			cv::Mat submat = temp.rowRange(0,srcs[0].rows);
			srcs[i].copyTo(submat);
			submat = temp.rowRange(srcs[0].rows,srcs[0].rows + srcs[0].rows);
			srcs[i + thedataSize].copyTo(submat);
			traindata.push_back(temp);
		}
		std::vector<std::vector<float>> descriptors(thedataSize);
		for(int i = 0;i < thedataSize ;i++)
			hog.HOGCompute(traindata[i],descriptors[i]);
		for(int i = 0 ;i < thedataSize; i++)
			traindatamat.push_back(cv::Mat(descriptors[i]));


		cv::Mat temp(traindatamat[0].rows,thedataSize,traindatamat[0].type());
		for(int i = 0; i < thedataSize; i++)
		{
			cv::Mat submat = temp.colRange(i,i+1);
			traindatamat[i].copyTo(submat);
		}
		svmtraindata = temp;
}

cv::Mat DataProcess::append(cv::Mat &Rmat)
{
	cv::Mat traindata(svmtraindata.rows,svmtraindata.cols + Rmat.cols,svmtraindata.type());
	cv::Mat temp = traindata.colRange(0,svmtraindata.cols);
	svmtraindata.copyTo(temp);
	temp = traindata.colRange(svmtraindata.cols,svmtraindata.cols + Rmat.cols);
	Rmat.copyTo(temp);
	return traindata;
}

cv::Mat DataProcess::append(cv::Mat &Lmat, cv::Mat &Rmat)
{
	cv::Mat traindata(Lmat.rows,Lmat.cols + Rmat.cols,Lmat.type());
	cv::Mat temp = traindata.colRange(0,Lmat.cols);
	Lmat.copyTo(temp);
	temp = traindata.colRange(Lmat.cols,Lmat.cols + Rmat.cols);
	Rmat.copyTo(temp);
	return traindata;
}
