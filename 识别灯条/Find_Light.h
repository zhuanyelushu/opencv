#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

class Find_Light
{
public:
	Mat src, img, blue_src, dstimg, drawimg;
	vector<Mat>src1;
	int threshold_v = 150;

	vector<vector<Point>> Cpoint1;//定义findContours的轮廓和层次结构
	vector<Vec4i> hierarchy;


	bool Callback();

};

