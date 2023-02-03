#include "Find_Light.h"
Find_Light f;

void g(int, void*)
{
    f.Callback();
}

int main()
{
    f.src = imread("C://Users//86185//Desktop//14.png"); //引用图片，三转一
    split(f.src, f.src1);
    imshow("1", f.src1[0]);
    f.blue_src = f.src1[0];
    cout << 1;
    Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));//获取自定义核心，膨胀，降噪
    dilate(f.blue_src, f.blue_src, element);
    blur(f.blue_src, f.blue_src, Size(1, 1));

    namedWindow("输出", 0);
    imshow("原图", f.src);
    cout << 2;
    createTrackbar("阈值", "输出", &f.threshold_v, 255, g); //滑动条
    g(0, 0);
    cout << 3;
    waitKey(0);
    return 0;
}