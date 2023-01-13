#pragma once
#ifndef ARMORDESCRIPTOR_H
#define ARMORDESCRIPTOR_H

#include"LightDescriptor.h"
#include"ArmorParam.h"
#include<opencv2/opencv.hpp>
#include<vector>
using namespace cv;
#define BIG_ARMOR 1
#define SMALL_ARMOR 0
#define UNKNOWN_ARMOR -1


class ArmorDescriptor
{
public:
    //ȫ����ʼ��Ϊ0
    ArmorDescriptor();

    //����װ�װ�ĸ������ݣ������ĸ���������ꡢ�÷ֺͱ���װ�װ��ͼ��д�뵽���������
    ArmorDescriptor(const LightDescriptor& lLight, const LightDescriptor& rLight, const int armorType, const cv::Mat& srcImg, const float rotationScore, ArmorParam param);

    //���װ�װ���Ϣ
    void clear()
    {
        rotationScore = 0;
        sizeScore = 0;
        distScore = 0;
        finalScore = 0;
        for (int i = 0; i < 4; i++)
        {
            vertex[i] = cv::Point2f(0, 0);
        }
        type = UNKNOWN_ARMOR;
    }

    //���װ�װ��ͼƬ
    void getFrontImg(const cv::Mat& grayImg);

    //�ж��Ƿ�Ϊװ�װ壨δʵ�֣�
    bool isArmorPattern() const;

public:
    std::array<cv::RotatedRect, 2> lightPairs; //0 left, 1 right
    float sizeScore;		//S1 = e^(size)
    float distScore;		//S2 = e^(-offset)
    float rotationScore;		//S3 = -(ratio^2 + yDiff^2)
    float finalScore;

    std::vector<cv::Point2f> vertex; //װ�װ���ĸ����㣬��������������
    cv::Mat frontImg; //��ͨ����װ�װ�ͼ��

    //	0 -> small
    //	1 -> big
    //	-1 -> unkown
    int type;
};



#endif // ARMORDESCRIPTOR_H
