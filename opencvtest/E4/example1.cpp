#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat test1(3,1, CV_32FC3, cv::Scalar(1.0f, 0.0f, 1.0f));
	cv::Mat test2(3,3, CV_32FC3, cv::Scalar(1.0f, 0.0f, 1.0f));
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	return 0;
}
