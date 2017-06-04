#include "SVMClassifier.h"

SVMClassifier::SVMClassifier()
{
	svm = cv::ml::SVM::create();
}

SVMClassifier::~SVMClassifier()
{
}

void SVMClassifier::InitialSVM(cv::ml::SVM::Types types, cv::ml::SVM::KernelTypes kerneltypes, cv::TermCriteria termcriteria)
{
	svm->setType(types);
	svm->setKernel(kerneltypes);
	svm->setTermCriteria(termcriteria);
}

void SVMClassifier::Train(cv::Mat &trainingDataMat, cv::Mat &labelsMat, cv::ml::SampleTypes types) const
{
	svm->train(trainingDataMat, types, labelsMat);
}

void SVMClassifier::SaveModel()
{
	svm->save("svm.xml");
}

void SVMClassifier::LoadModel(const char *filename)
{
	svm = cv::Algorithm::load<cv::ml::SVM>(filename);
}

float SVMClassifier::Predict(cv::Mat &Input,cv::Mat &Output) const
{
	return svm->predict(Input,Output);
}

float SVMClassifier::Predict(cv::Mat & Input) const
{
	return svm->predict(Input);
}
