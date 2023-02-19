#include "Find_Light.h"
using namespace std;
using namespace cv;

Find_Light f;

 
int main()
{
	f.src = imread("C://Users//86185//Desktop//14.png");
	f.src1 = f.src;
	f.Picture();
	f.Callback();
	f.Sureback();
	waitKey();
}