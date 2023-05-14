#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat lenna = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("lenna", lenna);

	for (int r = 0; r < lenna.rows; r++)
		for (int c = 0; c < lenna.cols; c++)
			lenna.at<uchar>(r, c) = lenna.at<uchar>(r, c) + 30; // �����÷ο� ���ɼ� ����
			  // saturate_cast<uchar>(img.at<uchar>(r, c) + 30) ������ 0����, 255�̻��� 255�� ��ȯ
	imshow("lenna", lenna);
	waitKey();
	return 0;
}