#include "Find_Light.h"

bool Find_Light::Callback()
{


    threshold(blue_src, dstimg, threshold_v, 255, THRESH_BINARY);
    imshow("二值化", dstimg);
    cout << 4;
    vector<vector<Point>> Cpoint1;//定义findContours的轮廓和层次结构
    vector<Vec4i> hierarchy;
    findContours(dstimg, Cpoint1, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//寻找轮廓


    vector<vector<Point>>Cpoint2(Cpoint1.size());//定义点集
    vector<Rect> pointRect(Cpoint1.size());
    vector<RotatedRect> minRects(Cpoint1.size());
    drawimg = Mat::zeros(src.size(), src.type());

    for (int i = 0; i < Cpoint1.size(); i++)
    {
        approxPolyDP(Cpoint1[i], Cpoint2[i], 1, true);// 对图像轮廓点进行多边形拟合
        //(图像的轮廓点组成的点集,输出的多边形点集
        //,另个轮廓点之间最大距离数,是否封闭)

        pointRect[i] = boundingRect(Cpoint2[i]); //计算轮廓的垂直边界最小矩形，矩形是与图像上下边界平行的
        minRects[i] = minAreaRect(Cpoint2[i]);

    }
    cout << 5;


    for (int t = 0; t < Cpoint1.size(); t++)
    {
        Point2f pts[4];
        if (Cpoint2[t].size() > 5 && Cpoint2[t].size() < 10)
        {

            minRects[t].points(pts);
            for (int r = 0; r < 4; r++)
                line(drawimg, pts[r], pts[(r + 1) % 4], Scalar(0, 30, 255), 2, LINE_AA);

        }

    }
    cout << 6;
    img = src + drawimg;
    imshow("输出", img);

    return 1;
}