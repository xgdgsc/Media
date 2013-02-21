#ifndef HISTONORM_H
#define HISTONORM_H

#include <QDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include"point.h"
#include"libs.h"

using namespace std;
using namespace cv;

namespace Ui {
  class histonorm;
}

class histonorm : public QDialog
{
  Q_OBJECT
  
public:
  explicit histonorm(QWidget *parent = 0);
  ~histonorm();
  void normHisto(Mat mtx);
  Mat mtx;
  Mat mtx_norm;
  int s[256];
  int histo[256];
private:
  Ui::histonorm *ui;
};

#endif // HISTONORM_H
