
#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

class Find_Light
{
public:
	Mat src, src1, img, dstimg, drawimg, end, gray;
	vector<Mat>channels;
	vector<vector<Point>> Cpoint1;//�����̳ж���findContours�������Ͳ�νṹ
	float width;
	float length;

	Mat Picture();
	Mat Callback();
	Mat Sureback();

};