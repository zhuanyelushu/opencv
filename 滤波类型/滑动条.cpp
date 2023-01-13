//对所给图片进行二值化和滤波处理筛出灯条，
//配上三个滑动条，分别用于调整二值化阈值，用于调整所选滤波模式，用于调整滤波核大小。
//图片展示和滑动条分在两个窗口。

#include"fl.h"
Find_Line fl;
void g(int, void*)
{
	fl.process();
}


int main()
{
	fl.src = imread("D://视觉入门//素材//14.png");
	imshow(window, fl.src);
	cvtColor(fl.src, fl.src, COLOR_RGB2GRAY);
	namedWindow(window1, 0);//一定要注意，创建滑动条的时候，一定要定义窗口。
	createTrackbar("类型控制", window1, &fl.tbar, 4, g);
	g(fl.tbar, 0);
	createTrackbar("核大小控制", window1, &fl.conttolbar, fl.maxctlbar, g);
	g(fl.conttolbar, 0);
	createTrackbar("参数值",  window1, &fl.g_nThresholdValue, 255, g);
	g(fl.g_nThresholdValue, 0);
	waitKey();
	return 0;
}