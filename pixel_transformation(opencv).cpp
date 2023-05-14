#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat lenna = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("lenna", lenna);

	Mat lenna2;
	lenna.convertTo(lenna2, -1, 1, 30); // lenna2(x, y) = saturate_cast<rtype>(alpha x (*this)(x, y) + beta)

	imshow("lenna2", lenna2);
	waitKey();
	return 0;
}