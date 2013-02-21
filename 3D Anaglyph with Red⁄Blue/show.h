#ifndef SHOW_H
#define SHOW_H

#include <QDialog>
#include<QFileDialog>
#include<opencv2/opencv.hpp>
#include<QImage>
#include<QDebug>
#include<QMessageBox>
#include"libs.h"
using namespace cv;

namespace Ui {
  class Show;
}

class Show : public QDialog
{
  Q_OBJECT
  
public:
  explicit Show(QWidget *parent = 0);
  ~Show();
  void setAnaglyph(Mat mtx);
public slots:
  void saveImage();
private:
  Mat mtx_anaglyph;
  Ui::Show *ui;
};

#endif // SHOW_H
