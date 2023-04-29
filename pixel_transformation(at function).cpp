#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat lenna = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("lenna", lenna);

	for (int r = 0; r < lenna.rows; r++)
		for (int c = 0; c < lenna.cols; c++)
			lenna.at<uchar>(r, c) = lenna.at<uchar>(r, c) + 30; // 오버플로우 가능성 있음
			  // saturate_cast<uchar>(img.at<uchar>(r, c) + 30) 음수는 0으로, 255이상을 255로 변환
	imshow("lenna", lenna);
	waitKey();
	return 0;
}