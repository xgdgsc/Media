#ifndef LIBS_H
#define LIBS_H
//#include"fundamental.h"
#include<opencv2/opencv.hpp>
#include<QImage>
#include<QDebug>
using namespace cv;

 QImage IplImage2QImage(const _IplImage *iplImage);
 IplImage* qImage2IplImage(const QImage& qImage);
 double CalcMSE(Mat origin,Mat approx);
 double CalcPSNR(double mse);
 double myPSNR(Mat origin,Mat approx);

#ifdef Q_WS_WIN
double PSNR(Mat origin, Mat approx);
#endif
#endif // LIBS_H
