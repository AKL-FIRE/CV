/*
 * train_run.cpp
 *
 *  Created on: 2017年4月2日
 *      Author: lcy
 */

#include "HOGFeature.hpp"
#include "SVMClassifier.h"
#include "DataProcess.hpp"

int main()
{
	DataProcess proc1(20);
	proc1.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/大家好35/helloleft35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/大家好35/helloright35-"));
	std::cout << proc1.getsvmtraindata().rows << " x " << proc1.getsvmtraindata().cols << std::endl;

	DataProcess proc2(20);
	proc2.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/我叫陈敏35/cm-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/我叫陈敏35/cm-right35-"));
	std::cout << proc2.getsvmtraindata().rows << " x " << proc2.getsvmtraindata().cols << std::endl;

	DataProcess proc3(20);
	proc3.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/很高兴见到你35/nice2seeu-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/很高兴见到你35/nice2seeu-right35-"));
	std::cout << proc3.getsvmtraindata().rows << " x " << proc3.getsvmtraindata().cols << std::endl;

	DataProcess proc4(20);
	proc4.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/你叫什么名字35/your-name-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/你叫什么名字35/your-name-right35-"));
	std::cout << proc4.getsvmtraindata().rows << " x " << proc4.getsvmtraindata().cols << std::endl;

	DataProcess proc5(20);
	proc5.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/切换35/exchange-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/切换35/exchange-right35-"));
	std::cout << proc5.getsvmtraindata().rows << " x " << proc5.getsvmtraindata().cols << std::endl;

	DataProcess proc6(20);
	proc6.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/我感觉不舒服35/I-feel-terrible-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/我感觉不舒服35/I-feel-terrible-right35-"));
	std::cout << proc6.getsvmtraindata().rows << " x " << proc6.getsvmtraindata().cols << std::endl;

	DataProcess proc7(20);
	proc7.process(std::string("/home/lcy/workspace/KCF2/训练样本/35/thanks/thanks-left35-"),std::string("/home/lcy/workspace/KCF2/训练样本/35/thanks/thanks-right35-"));
	std::cout << proc7.getsvmtraindata().rows << " x " << proc7.getsvmtraindata().cols << std::endl;

	cv::Mat traindatasvm;
	proc1.getsvmtraindata().copyTo(traindatasvm);
	traindatasvm = DataProcess::append(traindatasvm,proc2.getsvmtraindata());
	traindatasvm = DataProcess::append(traindatasvm,proc3.getsvmtraindata());
	traindatasvm = DataProcess::append(traindatasvm,proc4.getsvmtraindata());
	traindatasvm = DataProcess::append(traindatasvm,proc5.getsvmtraindata());
	traindatasvm = DataProcess::append(traindatasvm,proc6.getsvmtraindata());
	traindatasvm = DataProcess::append(traindatasvm,proc7.getsvmtraindata());
	std::cout << traindatasvm.rows << " x " << traindatasvm.cols << std::endl;

	int labels[140];
	for(int i = 0; i < 20; i++)
		labels[i] = 1;
	for(int i = 20; i < 40; i++)
		labels[i] = 2;
	for(int i = 40; i < 60; i++)
		labels[i] = 3;
	for(int i = 60; i < 80; i++)
		labels[i] = 4;
	for(int i = 80; i < 100; i++)
		labels[i] = 5;
	for(int i = 100; i < 120; i++)
		labels[i] = 6;
	for(int i = 120; i < 140; i++)
		labels[i] = 7;
	cv::Mat labelsMat(140, 1, CV_32SC1, labels);

	SVMClassifier svm;
	svm.InitialSVM(cv::ml::SVM::Types::C_SVC,cv::ml::SVM::KernelTypes::LINEAR,cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS,500,1e-5));
	svm.Train(traindatasvm,labelsMat,cv::ml::SampleTypes::COL_SAMPLE);
	svm.SaveModel();
	std::cout << "done.";
}


