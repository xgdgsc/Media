#include "geometry_ui.h"
#include "ui_geometry.h"
#include"fundamental.h"

Geometry::Geometry(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Geometry)
{
  ui->setupUi(this);

  ui->label->setBackgroundRole(QPalette::Base);
  ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label->setScaledContents(true);
  ui->label_2->setBackgroundRole(QPalette::Base);
  ui->label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_2->setScaledContents(true);
}

Geometry::~Geometry()
{
  delete ui;
}

void Geometry::horizontalMirror(Mat mtx)
{
  horiMirror(mtx,&mtx_h);
  IplImage* img=new IplImage(mtx);
  IplImage* img_mirror=new IplImage(mtx_h);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_mirror=IplImage2QImage(img_mirror);
  //QImage qimg((uchar*)mtxQimg.data,mtxQimg.cols,mtxQimg.rows,QImage::Format_RGB32);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_mirror));
  repaint();
  show();
}

void Geometry::verticalMirror(Mat mtx)
{
  vertMirror(mtx,&mtx_v);
  IplImage* img=new IplImage(mtx);
  IplImage* img_mirror=new IplImage(mtx_v);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_mirror=IplImage2QImage(img_mirror);
  //QImage qimg((uchar*)mtxQimg.data,mtxQimg.cols,mtxQimg.rows,QImage::Format_RGB32);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_mirror));
  repaint();
  show();
}

void ImageDisplayer::on_action_Horizontal_Mirror_triggered()
{
  this->horizontal.horizontalMirror(mtx_color);
}

void ImageDisplayer::on_action_Vertical_Mirror_triggered()
{
  this->vertical.verticalMirror(mtx_color);
}

void ImageDisplayer::on_action_Affine_Transformation_triggered()
{
  this->aff.showAffine(mtx_color);
}
