#include "opencv2/cv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat lenna = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("lenna", lenna);

	for (int r = 0; r < lenna.rows; r++)
	{
		uchar* p = lenna.ptr<uchar>(r);
		for (int c = 0; c < lenna.cols; c++)
			p[c] = saturate_cast<uchar>(p[c] + 30);
	}
	imshow("lenna", lenna);
	waitKey();
	return 0;
}