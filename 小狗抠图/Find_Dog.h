#include<opencv2/core/core.hpp>
#include<opencv2/core/base.hpp>
#include<opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class Find_Dog
{
public:
    Mat img;
    Mat gray, dst1;
    Mat result;
    double exchange = 170;

    Mat Deal_Img();
};