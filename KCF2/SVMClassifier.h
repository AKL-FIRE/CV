/*
This file will use SVM to classify the image by the orbit.
*/

#ifndef _SVMCLASSIFIER_
#define _SVMCLASSIFIER_ 



#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>

class SVMClassifier
{
public:
	SVMClassifier();
	~SVMClassifier();
	void InitialSVM(cv::ml::SVM::Types types,cv::ml::SVM::KernelTypes kerneltypes,cv::TermCriteria termcriteria);//Initial the params of SVM
	void Train(cv::Mat &trainingDataMat, cv::Mat &labelsMat,cv::ml::SampleTypes types) const;//Train the SVM with samples
	void SaveModel();//Save the SVM model
	void LoadModel(const char * filename);//Load the SVM model
	float Predict(cv::Mat &Input, cv::Mat &Output) const;//Use the SVM to predict data
	float Predict(cv::Mat &Input) const;

private:
	cv::Ptr<cv::ml::SVM> svm;
};

#endif // !_SVMCLASSIFIER_