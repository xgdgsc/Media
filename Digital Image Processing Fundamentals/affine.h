#ifndef AFFINE_H
#define AFFINE_H

#include <QDialog>

#include<QFileDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
namespace Ui {
  class affine;
}

class affine : public QDialog
{
  Q_OBJECT
  
public:
  explicit affine(QWidget *parent = 0);
  ~affine();
  Mat mtx,mtx_rot,mtx_sca,mtx_warp;
  void showAffine(Mat mtx);
public slots:
  void showRotate();
  void showScale();
  void showWarp();
private:
  Ui::affine *ui;
};

#endif // AFFINE_H
