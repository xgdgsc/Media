#ifndef LINEARTRANS_H
#define LINEARTRANS_H

#include <QDialog>
#include<opencv2/opencv.hpp>
#include"point.h"
#include"libs.h"
using namespace cv;

namespace Ui {
  class linearTrans;
}

class linearTrans : public QDialog
{
  Q_OBJECT
  
public:
  explicit linearTrans(QWidget *parent = 0);
  ~linearTrans();
  Mat mtx_linear_trans;
  Mat mtx;
  double a,b;
  void showLinearTrans(Mat mtx);
public slots:
  void showLinearTrans();
private:
  Ui::linearTrans *ui;
};

#endif // LINEARTRANS_H
