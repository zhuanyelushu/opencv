#include"Find_Dog.h"
#include<opencv2/core/core.hpp>
Mat Find_Dog::Deal_Img()
{
  
    cvtColor(img, gray, COLOR_BGR2GRAY);//��תΪ�Ҷ�ͼ
    threshold(gray, dst1, 170, 255, THRESH_BINARY_INV);
    cvtColor(dst1, dst1, COLOR_BayerBG2BGR);
    cvtColor(img, img, COLOR_HSV2BGR);
    bitwise_and(dst1, img, result);
    return result;
}