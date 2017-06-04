#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
	Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();

	Mat img_1 = imread("../img/3.jpg");
	Mat img_2 = imread("../img/4.jpg");

	vector<KeyPoint> keypoints_1, keypoints_2;
	f2d->detect(img_1, keypoints_1);
	f2d->detect(img_2, keypoints_2);

	Mat descriptors_1, descriptors_2;
	f2d->compute(img_1, keypoints_1, descriptors_1);
	f2d->compute(img_2, keypoints_2, descriptors_2); 

	 BFMatcher matcher;
	 vector<DMatch> matches;
	 matcher.match(descriptors_1, descriptors_2, matches);

	 Mat img_matches;
	 drawMatches(img_1, keypoints_1, img_2, keypoints_2, matches, img_matches);
	 imshow("【match图】", img_matches);

	 waitKey(0);
}
