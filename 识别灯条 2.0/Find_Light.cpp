#include "Find_Light.h"

Mat  Find_Light::Picture()
{

    split(src, channels);
    gray = channels[0];
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));//获取自定义核心，膨胀，降噪
    dilate(gray, gray, element);
    blur(gray, gray, Size(3, 3));
    return gray;

}

Mat  Find_Light::Callback()
{
    threshold(gray, img, 130, 255, THRESH_BINARY);
    imshow("二值化", img);

    Canny(img, dstimg, 10, 30, 3);
    imshow("轮廓", dstimg);

    findContours(dstimg, Cpoint1, RETR_EXTERNAL, CHAIN_APPROX_NONE);//寻找轮廓
    Mat dst2(img.size(), CV_8UC1, Scalar(0));
    drawContours(dst2, Cpoint1, -1, Scalar(255), 1);
    return dst2;

}

Mat  Find_Light::Sureback()
{
    Mat dst2(img.size(), CV_8UC3, Scalar(0));

    for (int i = 0; i < Cpoint1.size(); i++)
    {
        RotatedRect r = minAreaRect(Cpoint1[i]);

        float a = r.size.height / r.size.width;
        if (a < 1)
            a = 1 / a;

        if (a > 2.2)
        {
            Point2f p[4];
            r.points(p);
            for (int j = 0; j < 4; j++)
                line(dst2, p[j], p[(j + 1) % 4], Scalar(0, 0, 255), 1, LINE_AA);
        }
    }
    end = src1 + dst2;
    imshow("输出", end);
    imshow("输出2", dst2);
    return dst2;
}

