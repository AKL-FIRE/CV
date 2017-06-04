#include "DataProcess.h"

DataProcess::DataProcess()
{
}

DataProcess::~DataProcess()
{
}

bool DataProcess::DataLoad(const char * filename,int numbers)
{
	cv::FileStorage fs(filename, cv::FileStorage::READ);
	if (!fs.isOpened())
	{
		std::cout << "Open File Error" << std::endl;
		return false;
	}
	std::vector<cv::Mat> temp;
	
	for (int i = 0; i < numbers; i++)
	{
		std::strstream strnum;
		strnum << i;
		std::string str1,str("mat");
		strnum >> str1;
		str.append(str1);
		cv::Mat data;
		fs[str] >> data;
		temp.push_back(data);
	}
	fs.release();
	mat = temp;
	return true;
}

void DataProcess::resizeMat(cv::Size size)
{
	for (auto c : mat)
	{
		cv::resize(c, c, size);
	}
}

void DataProcess::MatExpend()
{
	std::vector<cv::Mat> temp;

	for (auto c : mat)
	{
		temp.push_back(c.reshape(0, 1));
	}
	mat = temp;
}

bool DataProcess::mergeRows()
{
	if (mat.size() == 0)
		return false;
	int totalRows = mat.size() * mat[0].rows;
	cv::Mat mergeDescriptors(totalRows, mat[0].cols, mat[0].type());
	int count = 0;
	for (auto c : mat)
	{
		cv::Mat submat = mergeDescriptors.rowRange(count, count + 1);
		c.copyTo(submat);
		count++;
	}
	BigMatrix = mergeDescriptors;
	return true;
}

void DataProcess::Start(const char *filename,int number)
{
	this->DataLoad(filename, number);
	this->MatExpend();
	this->mergeRows();
}

cv::Mat DataProcess::append(DataProcess & data2)
{
	cv::Mat data2_matrix = data2.getBigMatrix();
	cv::Mat temp(BigMatrix.rows + data2_matrix.rows, BigMatrix.cols, BigMatrix.type());
	cv::Mat submat = temp.rowRange(0, BigMatrix.rows);
	BigMatrix.copyTo(submat);
	submat = temp.rowRange(BigMatrix.rows, BigMatrix.rows + data2_matrix.rows);
	data2_matrix.copyTo(submat);
	return temp;
}

void DataProcess::setBigMatrix(const cv::Mat & mat)
{
	BigMatrix = mat;
}

cv::Mat DataProcess::getBigMatrix()
{
	return BigMatrix;
}

std::vector<cv::Mat> DataProcess::getmat()
{
	return mat;
}

cv::Mat DataProcess::PcaProcess(int dimension)
{
	if (BigMatrix.empty())
		std::cout << "No Data";
	BigMatrix.convertTo(BigMatrix, CV_32FC1);
	std::cout << BigMatrix.cols;
	cv::PCA pca(BigMatrix, cv::Mat(), cv::PCA::DATA_AS_ROW, dimension);
	cv::Mat result(BigMatrix.rows, dimension, BigMatrix.type());
	for (int i = 0; i < BigMatrix.rows; i++)
	{
		cv::Mat projectedMat(1, dimension, BigMatrix.type());
		pca.project(BigMatrix.row(i), projectedMat);
		result.row(i) = projectedMat.row(0) + 0;
	}
	return result;
}

