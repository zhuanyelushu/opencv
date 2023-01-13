#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#define window  "【原图 】"
#define window1 "【结果1】"

using namespace std;
using namespace cv;


class Find_Line
{
public:

	Mat src, dst;
	int tbar = 1;
	int conttolbar = 3;
	int g_nThresholdValue = 100;
	int maxctlbar = 40;//控制滤波效果，核的范围。
	int x;
	



	bool process();
};

bool Find_Line ::process()
{

	x = 2 * conttolbar + 1;
	if (tbar == 0)
	{

		boxFilter(src, dst, -1, Size(x, x));//方形滤波
	}
	if (tbar == 1)
	{
		blur(src, dst, Size(x, x));//均值滤波
	}
	if (tbar == 2)
	{
		GaussianBlur(src, dst, Size(x, x), 0, 0);//高斯滤波
	}
	if (tbar == 3)
	{
		medianBlur(src, dst, 3);//中值滤波
	}
	if (tbar == 4)
	{
		bilateralFilter(src, dst, 25, 25 * 2, 25 / 2);
	}

	threshold(dst, dst, g_nThresholdValue, 255, 0);

	imshow(window1, dst);
	return 0;
}
