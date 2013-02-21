#ifndef ANTICOLOR_H
#define ANTICOLOR_H

#include <QDialog>
#include<opencv2/opencv.hpp>
#include"point.h"
#include"libs.h"

namespace Ui {
  class anticolor;
}

class anticolor : public QDialog
{
  Q_OBJECT
  
public:
  explicit anticolor(QWidget *parent = 0);
  ~anticolor();
  void anti(Mat mtx);
  Mat mtx;
  Mat mtx_anti;
private:
  Ui::anticolor *ui;
};

#endif // ANTICOLOR_H
