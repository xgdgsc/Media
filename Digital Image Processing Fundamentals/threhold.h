#ifndef THREHOLD_H
#define THREHOLD_H

#include <QDialog>
#include<opencv2/opencv.hpp>
#include"point.h"
#include"libs.h"

using namespace cv;
namespace Ui {
  class threhold;
}

class threhold : public QDialog
{
  Q_OBJECT
  
public:
  explicit threhold(QWidget *parent = 0);
  ~threhold();
  Mat mtx;
  Mat mtx_thr;
  void showThrehold(Mat mtx);
public slots:
    void showThrehold();
private:
  Ui::threhold *ui;
};

#endif // THREHOLD_H
