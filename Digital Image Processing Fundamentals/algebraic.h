#ifndef ALGEBRAIC_H
#define ALGEBRAIC_H

#include<opencv2/opencv.hpp>
#include<iostream>


using namespace std;
using namespace cv;

void calcAdd(Mat mtx,Mat mtx2,Mat* add);
void calcSub(Mat mtx,Mat mtx2,Mat* subs);


#endif // ALGEBRAIC_H
