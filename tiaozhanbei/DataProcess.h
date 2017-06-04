/*
This class is used to process the Data from the xml files 
*/
#ifndef _DATAPROCESS_
#define _DATAPROCESS_

#include <opencv2/opencv.hpp>
#include <vector>
#include <strstream>

class DataProcess
{
public:
	DataProcess();
	~DataProcess();
	bool DataLoad(const char *filename,int numbers);// Load the image,numbers is the number of images
	void resizeMat(cv::Size size);
	void MatExpend();//convert the image to row vector
	bool mergeRows();//generate the BigMatrix
	void Start(const char *filename, int number);//automatically handle the data
	cv::Mat append(DataProcess &data2);//combine data1 with data2
	void setBigMatrix(const cv::Mat &mat);//set the BigMatrix
	cv::Mat PcaProcess(int dimension);//use pca to process the data
	cv::Mat getBigMatrix();//return the BigMatrix
	std::vector<cv::Mat> getmat();//return the mats vector
private:
	std::vector<cv::Mat> mat;//a vector of Mat store the rpw vector
	cv::Mat BigMatrix;//each row is a sample
};
//it must run by 1. DataLoad 2.MatExpend 3.mergeRows

#endif // !_DATAPROCESS_

