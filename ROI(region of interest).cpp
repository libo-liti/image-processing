#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat a = imread("lenna.jpg", IMREAD_COLOR);
	Rect roi(10, 10, 100, 100); // (x, y, w, h)
	Mat b = a(roi);
	imshow("roi", b);

	waitKey(0);
	return 0;
}