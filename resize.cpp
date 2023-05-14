#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat lenna = imread("d:/lenna.jpg");
	imshow("lenna", lenna);

	Mat resize_lenna = lenna.clone();
	resize(lenna, resize_lenna, Size(100, 100));
	imshow("resize", resize_lenna);

	waitKey();
	return 0;
}