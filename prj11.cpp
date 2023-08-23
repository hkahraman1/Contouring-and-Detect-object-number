#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat resim = imread("seker.jpg", IMREAD_GRAYSCALE);
	threshold(resim, resim, 190, 155, THRESH_BINARY_INV);
	vector<vector<Point>> konturlama;
	vector<Vec4i> tespit;
	findContours(resim, konturlama, tespit, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	RotatedRect dik;
	

	for (int i = 0; i < konturlama.size(); i++)
	{
		drawContours(resim, konturlama, i, Scalar(10,200,70), 1);
		dik = minAreaRect(konturlama[i]);
		putText(resim, format("%d", i + 1), dik.center, FONT_HERSHEY_TRIPLEX, 1, Scalar(0, 200, 245), 1);
		cout << "seker bulundu" << endl;

	}
	imshow("ilk hal", resim);
	waitKey(0);
}