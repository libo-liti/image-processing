#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../image/lenna.jpg");
	Mat dst;

	blur(src, dst, Size(10, 10));

	imshow("source", src);
	imshow("result", dst);

	waitKey();
	return 0;
}