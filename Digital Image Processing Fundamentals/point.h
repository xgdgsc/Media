#ifndef POINT_H
#define POINT_H

#include<opencv2/opencv.hpp>
#include<iostream>


using namespace std;
using namespace cv;
void calcHist(Mat img,int* result);
void calcLinear(Mat img,Mat *Lt,double a,double b);
void calcAnti(Mat img_color,Mat *anti);
void calcThreshold(Mat img,Mat *thr,int div);
void NormHist(Mat img,Mat *norm,int* histo,int* s);
void calcS(Mat img,int* histo,int *res);
#endif // POINT_H
