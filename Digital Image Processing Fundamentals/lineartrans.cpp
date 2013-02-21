#include "lineartrans.h"
#include "ui_lineartrans.h"

linearTrans::linearTrans(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::linearTrans)
{
  ui->setupUi(this);
  connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(showLinearTrans()));
  ui->label_4->setBackgroundRole(QPalette::Base);
  ui->label_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_4->setScaledContents(true);
  ui->label_5->setBackgroundRole(QPalette::Base);
  ui->label_5->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_5->setScaledContents(true);
}

linearTrans::~linearTrans()
{
  delete ui;
}

void linearTrans::showLinearTrans(Mat mtx)
{
  this->mtx=mtx;
  show();
}

void linearTrans::showLinearTrans()
{
  this->a=ui->lineEdit->text().toDouble();
  this->b=ui->lineEdit_2->text().toDouble();
  calcLinear(mtx,&mtx_linear_trans,a,b);
  IplImage* img=new IplImage(mtx);
  IplImage* img_linear_trans=new IplImage(mtx_linear_trans);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_linear_trans=IplImage2QImage(img_linear_trans);
  //QImage qimg((uchar*)mtxQimg.data,mtxQimg.cols,mtxQimg.rows,QImage::Format_RGB32);
  ui->label_5->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_4->setPixmap(QPixmap::fromImage(qmtx_linear_trans));
  repaint();
}
