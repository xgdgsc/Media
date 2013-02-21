#ifndef MORPHOLOGICAL_H
#define MORPHOLOGICAL_H
#include<opencv2/opencv.hpp>
#include<iostream>
//#include"geometry_ui.h"


using namespace std;
using namespace cv;

void erosion(Mat mtx,Mat *mtx_bin,Mat *mtx_ero);
void dilation(Mat mtx,Mat *mtx_bin,Mat *mtx_dil);
void erosion( Mat *mtx_bin, Mat *mtx_ero);
void dilation( Mat *mtx_bin, Mat *mtx_dil);
void thinning(Mat mtx,Mat *mtx_bin,Mat *mtx_thin);

#endif // MORPHOLOGICAL_H
