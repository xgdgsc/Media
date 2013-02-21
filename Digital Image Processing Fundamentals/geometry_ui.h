#ifndef GEOMETRY_UI_H
#define GEOMETRY_UI_H

#include <QDialog>
#include<QFileDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<opencv2/opencv.hpp>
#include<iostream>
#include"geometry.h"

using namespace std;
using namespace cv;

namespace Ui {
  class Geometry;
}

class Geometry : public QDialog
{
  Q_OBJECT
  
public:
  explicit Geometry(QWidget *parent = 0);
  ~Geometry();
  void horizontalMirror(Mat mtx);
  void verticalMirror(Mat mtx);
  Mat mtx,mtx_h,mtx_v;
private:
  Ui::Geometry *ui;
};

#endif // GEOMETRY_UI_H
