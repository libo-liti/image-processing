#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("d:/lenna.jpg");
	Mat dst;

	blur(src, dst, Size(11, 11));

	imshow("source", src);
	imshow("result", dst);

	waitKey();
	return 0;
}