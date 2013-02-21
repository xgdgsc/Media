#ifndef ALGEBRAIC_UI_H
#define ALGEBRAIC_UI_H

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
  class Algebraic;
}

class Algebraic : public QDialog
{
  Q_OBJECT
  
public:
  explicit Algebraic(QWidget *parent = 0);
  ~Algebraic();
  Mat mtx2,mtx2_color,mtx_add,mtx_sub;
  void addition(Mat mtx);
  void substraction(Mat mtx,int trans);
private:
  Ui::Algebraic *ui;
};




#endif // ALGEBRAIC_H
