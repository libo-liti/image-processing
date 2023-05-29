#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;

int main()
{
	Mat src, dst, erosion_dst, diation_dst, open_dst, close_dst, test;
	src = imread("../image/hangle.jpg", IMREAD_GRAYSCALE);
	//src = imread("../image/lenna.jpg", IMREAD_GRAYSCALE);
	resize(src, src, Size(700, 700));
	
	threshold(src, dst, 127, 255, THRESH_BINARY);
	dst = 255 - dst;
	imshow("original", dst);

	Mat element[3] = {};
	element[0] = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	element[1] = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(-1, -1));
	element[2] = getStructuringElement(MORPH_ELLIPSE, Size(3, 3), Point(-1, -1));


	erode(dst, erosion_dst, element[0]);
	imshow("erosion_rect", erosion_dst);

	erode(dst, erosion_dst, element[1]);
	imshow("erosion_cross", erosion_dst);

	erode(dst, erosion_dst, element[2]);
	imshow("erosion_ellipse", erosion_dst);


	dilate(dst, diation_dst, element[0]);
	imshow("diation_rect", diation_dst);

	dilate(dst, diation_dst, element[1]);
	imshow("diation_cross", diation_dst);

	dilate(dst, diation_dst, element[2]);
	imshow("diation_ellipse", diation_dst);

	morphologyEx(dst, open_dst, MORPH_OPEN, element[0]);
	imshow("open_dst", open_dst);

	morphologyEx(dst, close_dst, MORPH_CLOSE, element[0]);
	imshow("close_dst", close_dst);

	waitKey(0);
	return 0;
}
