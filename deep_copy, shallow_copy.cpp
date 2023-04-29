#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat lenna, deep_copy, shallow_copy;
	lenna = imread("lenna.jpg", IMREAD_COLOR);

	shallow_copy = lenna;
	deep_copy = lenna.clone(); // lenna.copyTo(deep_copy)

	waitKey(0);
	return 0;
}