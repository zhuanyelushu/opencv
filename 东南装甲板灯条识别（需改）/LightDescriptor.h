#pragma once
#ifndef LIGHTDESCRIPTOR_H
#define LIGHTDESCRIPTOR_H
#include<opencv2/opencv.hpp>
#include<vector>

//灯条描述类，其实就是把旋转矩阵的属性复制过来.
class LightDescriptor
{
public:
    LightDescriptor() {};
    LightDescriptor(const cv::RotatedRect& light)
    {
        width = light.size.width;
        length = light.size.height;
        center = light.center;
        angle = light.angle;
        area = light.size.area();
    }
    const LightDescriptor& operator =(const LightDescriptor& ld)
    {
        this->width = ld.width;
        this->length = ld.length;
        this->center = ld.center;
        this->angle = ld.angle;
        this->area = ld.area;
        return *this;
    }

    /*
    *	@Brief: return the light as a cv::RotatedRect object
    */
    cv::RotatedRect rec() const
    {
        return cv::RotatedRect(center, cv::Size2f(width, length), angle);
    }

public:
    float width;
    float length;
    cv::Point2f center;
    float angle;
    float area;
};

#endif //LIGHTDESCRIPTOR_H
