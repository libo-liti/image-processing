#include "opencv2/opencv.hpp"
using namespace cv;

Mat src;
Mat dst, detected_edges, dst_BINARY;
int lowThreshold = 60;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
Mat mask;
int d;
int b;


static void CannyThreshold(int, void*)
{
	blur(src, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold,
		lowThreshold * ratio, kernel_size);
	dst = Scalar::all(0);
	detected_edges.copyTo(dst);
	imshow("Canny", dst);
	threshold(dst, dst, 0, 255, THRESH_BINARY); // 이진화 수행
	imshow("binary", dst);
	for (int r = 0; r < dst.rows; r++)
		for (int c = 0; c < dst.cols; ++c)
			if (dst.at<uchar>(r, c) == 255)
				dst.at<uchar>(r, c) = src.at<uchar>(r, c);
	imshow("grayscale", dst);
	src.copyTo(mask, detected_edges);
	imshow("mask", mask);
}


int main()
{
	src = imread("../image/lenna.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }
	dst.create(src.size(), src.type());
	namedWindow("Canny");
	CannyThreshold(0, 0);

	waitKey(0);
	return 0;
}
