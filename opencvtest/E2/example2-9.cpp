#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{

	cv::Mat img_rgb, img_gray, img_pyr, img_pyr2, img_cny;
	img_rgb = cv::imread(argv[1]);
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gray, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);
	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);


	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(x,y);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "At(x,y) = (" << x << ", " << y << "): (blue, green, red) = (" << (unsigned int)blue << ", " << (unsigned int)green << ", " << (unsigned int)red << ")" << std::endl;

	std::cout << "Gray pixel there is: " << (unsigned int)img_gray.at<uchar>(y,x) << std::endl;

	x /= 4; y /= 4;
	std::cout << "Pyramid2 pixel there is: " << (unsigned int)img_pyr2.at<char>(y,x) << std::endl;

	img_cny.at<uchar>(x,y) = 128;

	return 0;
}

