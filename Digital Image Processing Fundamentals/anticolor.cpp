#include "anticolor.h"
#include "ui_anticolor.h"

anticolor::anticolor(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::anticolor)
{
  ui->setupUi(this);
  ui->label->setBackgroundRole(QPalette::Base);
  ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label->setScaledContents(true);
  ui->label_2->setBackgroundRole(QPalette::Base);
  ui->label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_2->setScaledContents(true);
}

anticolor::~anticolor()
{
  delete ui;
}

void anticolor::anti(Mat mtx)
{
  show();
  calcAnti(mtx,&mtx_anti);
  setWindowTitle("Anti-Color");
  IplImage* img=new IplImage(mtx);
  IplImage* img_anti=new IplImage(mtx_anti);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_anti=IplImage2QImage(img_anti);
  //QImage qimg((uchar*)mtxQimg.data,mtxQimg.cols,mtxQimg.rows,QImage::Format_RGB32);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_anti));
  repaint();
}
