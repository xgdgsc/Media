#include "morphological_ui.h"
#include "ui_morphological.h"
#include"fundamental.h"

Morphological::Morphological(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Morphological)
{
  ui->setupUi(this);
}

Morphological::~Morphological()
{
  delete ui;
}

void Morphological::erosionMorph(Mat mtx)
{

  this->mtx=mtx;
  erosion(mtx,&mtx_bin,&mtx_ero);

}

void Morphological::showErosion()
{
  show();
  IplImage* img=new IplImage(mtx_bin);
  IplImage* img_ero=new IplImage(mtx_ero);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_ero=IplImage2QImage(img_ero);
  //QImage qimg((uchar*)mtxQimg.data,mtxQimg.cols,mtxQimg.rows,QImage::Format_RGB32);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_ero));
  repaint();
}

void Morphological::dilationMorph(Mat mtx)
{
  this->mtx=mtx;
  dilation(mtx,&mtx_bin,&mtx_dil);
}

void Morphological::showDilation()
{
  show();
  IplImage* img=new IplImage(mtx_bin);
  IplImage* img_dil=new IplImage(mtx_dil);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_dil=IplImage2QImage(img_dil);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_dil));
  repaint();
}

void Morphological::openOperation(Mat mtx)
{
  show();
  erosionMorph(mtx);
  dilation(&mtx_ero,&mtx_open);
  IplImage* img=new IplImage(mtx_bin);
  IplImage* img_open=new IplImage(mtx_open);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_open=IplImage2QImage(img_open);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_open));

}

void Morphological::closeOperation(Mat mtx)
{
  show();
  dilationMorph(mtx);
  erosion(&mtx_dil,&mtx_close);
  IplImage* img=new IplImage(mtx_bin);
  IplImage* img_close=new IplImage(mtx_close);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_close=IplImage2QImage(img_close);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_close));
}

void Morphological::thin(Mat mtx)
{
  show();
  setWindowTitle("Thinning");
  thinning(mtx,&mtx_bin,&mtx_thin);
  IplImage* img=new IplImage(mtx_bin);
  IplImage* img_thin=new IplImage(mtx_thin);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_thin=IplImage2QImage(img_thin);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_thin));
}

void ImageDisplayer::on_action_Erosion_triggered()
{
  this->mp.erosionMorph(mtx);
  mp.showErosion();
}

void ImageDisplayer::on_action_Dilation_triggered()
{
  this->mp.dilationMorph(mtx);
  mp.showDilation();
}

void ImageDisplayer::on_action_Open_Operation_triggered()
{
  mp.openOperation(mtx);
}

void ImageDisplayer::on_action_Close_Operation_triggered()
{
  mp.closeOperation(mtx);
}

void ImageDisplayer::on_action_Thinning_triggered()
{
  mp.thin(mtx);
}
