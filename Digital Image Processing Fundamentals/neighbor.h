#ifndef NEIGHBOR_H
#define NEIGHBOR_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
//#include"geometry_ui.h"


using namespace std;
using namespace cv;



void calcEdge(Mat mtx,Mat* edge,string method);
void calcCanny(Mat mtx,Mat *edge,int lowThereshold);
void smoothNeighbor(Mat mtx,Mat* smooth);
void smoothGaussian(Mat mtx,Mat* smooth);
void smoothMedian(Mat mtx,Mat* smooth);

#endif // NEIGHBOR_H
