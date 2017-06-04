#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	cv::namedWindow("Example3",cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap(0);

	cv::Mat frame;
	while(true)
	{
		cap >> frame;
		if(frame.empty())
			break;
		cv::imshow("Example3",frame);
		if(cv::waitKey(30) == 27)
			break;
	}

	return 0;
}
