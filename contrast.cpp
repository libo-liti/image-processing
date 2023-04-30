#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	double alpha = 1.5;
	int beta = 50;
	Mat image = imread("d:/contrast.jpg");
	Mat image2;
	image.convertTo(image2, -1, alpha, beta);
	// image2 = image * alpha + beta;
	imshow("image", image);
	imshow("image2", image2);
	waitKey();
	return 0;
}