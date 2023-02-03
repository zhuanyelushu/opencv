#include "Find_Light.h"

bool Find_Light::Callback()
{


    threshold(blue_src, dstimg, threshold_v, 255, THRESH_BINARY);
    imshow("��ֵ��", dstimg);
    cout << 4;
    vector<vector<Point>> Cpoint1;//����findContours�������Ͳ�νṹ
    vector<Vec4i> hierarchy;
    findContours(dstimg, Cpoint1, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//Ѱ������


    vector<vector<Point>>Cpoint2(Cpoint1.size());//����㼯
    vector<Rect> pointRect(Cpoint1.size());
    vector<RotatedRect> minRects(Cpoint1.size());
    drawimg = Mat::zeros(src.size(), src.type());

    for (int i = 0; i < Cpoint1.size(); i++)
    {
        approxPolyDP(Cpoint1[i], Cpoint2[i], 1, true);// ��ͼ����������ж�������
        //(ͼ�����������ɵĵ㼯,����Ķ���ε㼯
        //,���������֮����������,�Ƿ���)

        pointRect[i] = boundingRect(Cpoint2[i]); //���������Ĵ�ֱ�߽���С���Σ���������ͼ�����±߽�ƽ�е�
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
    imshow("���", img);

    return 1;
}