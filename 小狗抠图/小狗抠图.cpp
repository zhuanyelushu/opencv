#include"Find_Dog.h"
#include<opencv2/core/core.hpp>
Find_Dog fl;

int main()
{
    fl.img = imread("C://Users//86185//Desktop//1.jpg");
    Mat result = fl.Deal_Img();


    imshow("end", fl.result);
    waitKey(0);

}
