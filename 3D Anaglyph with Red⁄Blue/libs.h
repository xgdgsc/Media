#ifndef LIBS_H
#define LIBS_H
#include<opencv2/opencv.hpp>
#include<QImage>
#include<QDebug>
using namespace cv;

 QImage IplImage2QImage(const _IplImage *iplImage);
 IplImage* qImage2IplImage(const QImage& qImage);


 void deleteBGchannel(Mat *mtx);
 void deleteRchannel(Mat *mtx);

#endif // LIBS_H
