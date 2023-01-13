#include "ArmorDescriptor.h"


ArmorDescriptor::ArmorDescriptor()
{
    rotationScore = 0;
    sizeScore = 0;
    vertex.resize(4);
    for (int i = 0; i < 4; i++)
    {
        vertex[i] = cv::Point2f(0, 0);
    }
    type = UNKNOWN_ARMOR;
}

ArmorDescriptor::ArmorDescriptor(const LightDescriptor& lLight, const LightDescriptor& rLight, const int armorType, const cv::Mat& grayImg, float rotaScore, ArmorParam _param)
{
    //获取两个灯条的旋转矩形
    lightPairs[0] = lLight.rec();
    lightPairs[1] = rLight.rec();

    cv::Size exLSize(int(lightPairs[0].size.width), int(lightPairs[0].size.height * 2));
    cv::Size exRSize(int(lightPairs[1].size.width), int(lightPairs[1].size.height * 2));
    cv::RotatedRect exLLight(lightPairs[0].center, exLSize, lightPairs[0].angle);
    cv::RotatedRect exRLight(lightPairs[1].center, exRSize, lightPairs[1].angle);

    cv::Point2f pts_l[4];
    exLLight.points(pts_l);
    cv::Point2f upper_l = pts_l[2];
    cv::Point2f lower_l = pts_l[3];

    cv::Point2f pts_r[4];
    exRLight.points(pts_r);
    cv::Point2f upper_r = pts_r[1];
    cv::Point2f lower_r = pts_r[0];

    vertex.resize(4);
    vertex[0] = upper_l;
    vertex[1] = upper_r;
    vertex[2] = lower_r;
    vertex[3] = lower_l;

    //设置装甲板类型
    type = armorType;
    //保存装甲板的图像
    getFrontImg(grayImg);

    rotationScore = rotaScore;

    // 计算尺寸分数
    float normalized_area = contourArea(vertex) / _param.area_normalized_base;
    sizeScore = exp(normalized_area);

    //计算装甲板和roi图像中心区域的距离分数
    //Point2f srcImgCenter(grayImg.cols / 2, grayImg.rows / 2);
    //灰度图中心点与装甲板中心点的距离
    //float sightOffset = cvex::distance(srcImgCenter, cvex::crossPointOf(array<Point2f, 2>{vertex[0],vertex[2]}, array<Point2f, 2>{vertex[1],vertex[3]}));
    //distScore = exp(-sightOffset / _param.sight_offset_normalized_base);

}

void ArmorDescriptor::getFrontImg(const Mat& grayImg)
{
    //using cvex::distance;
    const Point2f&
        tl = vertex[0],
        tr = vertex[1],
        br = vertex[2],
        bl = vertex[3];

    int width, height;
    if (type == BIG_ARMOR)
    {
        width = 92;
        height = 50;
    }
    else
    {
        width = 50;
        height = 50;
    }
    //透视变换
    Point2f src[4]{ Vec2f(tl), Vec2f(tr), Vec2f(br), Vec2f(bl) };
    Point2f dst[4]{ Point2f(0.0, 0.0), Point2f(width, 0.0), Point2f(width, height), Point2f(0.0, height) };
    const Mat perspMat = getPerspectiveTransform(src, dst);
    cv::warpPerspective(grayImg, frontImg, perspMat, Size(width, height));
}



