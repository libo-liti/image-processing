#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat image2 = imread("d:/image2.jpg");
	Mat logo = imread("d:/logo.png");

	Mat roi(image2, Rect(image2.cols - logo.cols, image2.rows - logo.rows, logo.cols, logo.rows));
	logo.copyTo(roi);
	imshow("result", image2);

	waitKey(0);
	return 0;
}