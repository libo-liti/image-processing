#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat a = Mat(400, 600, CV_8UC3);
	randu(a, Scalar::all(0), Scalar::all(255));
	imshow("img", a);

	waitKey(0);
	return 0;
}