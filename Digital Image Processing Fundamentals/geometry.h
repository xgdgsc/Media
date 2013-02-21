#ifndef GEOMETRY_H
#define GEOMETRY_H
#include<opencv2/opencv.hpp>
#include<iostream>
//#include"geometry_ui.h"
#define PI 3.14159265

using namespace std;
using namespace cv;


void horiMirror(Mat mtx,Mat * mirror);
void vertMirror(Mat mtx,Mat * mirror);
void rotate(Mat mtx,Mat *rot,double theta);
void scale(Mat mtx,Mat *sca,double factorx,double factory);
void warp(Mat mtx,Mat *warp,double facor);

#endif // GEOMETRY_H
