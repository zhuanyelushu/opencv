#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;

//全局变量
Mat g_ImageROI;
Rect g_rectangle;
Point g_startPoint;
Mat g_srcImage;
RNG g_rng(12345);
bool click_flag = 0;

void onMouse(int event, int x, int y, int flags, void* param)
{
	//鼠标移动事件
	if (event == EVENT_MOUSEMOVE)
	{
		if (click_flag == 1)
		{
			g_rectangle.x = MIN(g_startPoint.x, x);
			g_rectangle.y = MIN(g_startPoint.y, y);
			g_rectangle.width = abs(x - g_startPoint.x);
			g_rectangle.height = abs(y - g_startPoint.y);
			g_rectangle = g_rectangle & Rect(0, 0, g_srcImage.cols, g_srcImage.rows);
		}
	}

	//左键按下事件
	if (event == EVENT_LBUTTONDOWN)
	{
		g_startPoint.x = x;
		g_startPoint.y = y;
		click_flag = 1;
	}

	//左键弹起事件
	if (event == EVENT_LBUTTONUP)
	{
		click_flag = 0;

		//显示感兴趣区域的图片
		g_ImageROI = g_srcImage(g_rectangle);
		namedWindow("截取的图片", 0);
		imshow("截取的图片", g_ImageROI);
	}

}
void main()
{
	VideoCapture cap(0);

	namedWindow("摄像头", 0);
	setMouseCallback("摄像头", onMouse);

	//按"Esc"退出
	while (waitKey(30) != 27)
	{
		cap >> g_srcImage;

		//画矩形，边框随机颜色
		rectangle(g_srcImage, g_rectangle, cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)), 3);
		imshow("摄像头", g_srcImage);
	}
	destroyAllWindows();
	cap.release();
}