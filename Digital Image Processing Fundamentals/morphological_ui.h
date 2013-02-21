#ifndef MORPHOLOGICAL_UI_H
#define MORPHOLOGICAL_UI_H

#include <QDialog>

#include<QFileDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<opencv2/opencv.hpp>
#include<iostream>
#include"morphological.h"
using namespace std;
using namespace cv;

namespace Ui {
  class Morphological;
}

class Morphological : public QDialog
{
  Q_OBJECT
  
public:
  explicit Morphological(QWidget *parent = 0);
  ~Morphological();
  void erosionMorph(Mat mtx);
  void showErosion();
  void dilationMorph(Mat mtx);
  void showDilation();
  void openOperation(Mat mtx);
  void closeOperation(Mat mtx);
  void thin(Mat mtx);
  Mat mtx,mtx_bin,mtx_ero,mtx_dil,mtx_open,mtx_close,mtx_thin;
private:
  Ui::Morphological *ui;
};

#endif // MORPHOLOGICAL_UI_H
