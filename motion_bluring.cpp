#include "opencv2/opencv.hpp"
using namespace cv;
#define SIZE 7

int main()
{
	Mat image = imread("../image/lenna.jpg", IMREAD_GRAYSCALE);
	float weights[] = {
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	1.0 / SIZE, 1.0 / SIZE, 1.0 / SIZE, 1.0 / SIZE, 1.0 / SIZE, 1.0 / SIZE, 1.0 / SIZE,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0
	};
	Mat mask(SIZE, SIZE, CV_32F, weights);
	Mat blur;
	filter2D(image, blur, -1, mask);
	blur.convertTo(blur, CV_8U);
	imshow("image", image);
	imshow("motion_blur", blur);
	waitKey(0);
	return 0;
}
