#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat src = imread("../image/lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst_g, dst_m;
	Mat noise_img = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(noise_img, 0, 255);

	Mat black_img = noise_img < 10;
	Mat white_img = noise_img > 245;

	Mat src1 = src.clone();
	src1.setTo(255, white_img);
	src1.setTo(0, black_img);

	GaussianBlur(src1, dst_g, Size(7, 7), 0);
	blur(src1, dst_m, Size(7, 7));

	imshow("src", src);
	imshow("noise", src1);
	imshow("gaussian_blur", dst_g);
	imshow("median_blur", dst_m);

	waitKey(0);
	return 0;
}