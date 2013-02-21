
#include "ui_algebraic.h"
#include"fundamental.h"
#include "algebraic_ui.h"
#include"algebraic.h"
#include"libs.h"

Algebraic::Algebraic(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Algebraic)
{
  ui->setupUi(this);
}

Algebraic::~Algebraic()
{
  delete ui;
}

void Algebraic::addition(Mat mtx)
{
#ifdef Q_WS_X11
  QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"/home/gsc/Documents",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));
#endif

#ifdef Q_WS_WIN
  QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));
#endif
  if (!fileName.isEmpty())
    {
      mtx2_color=imread(fileName.toStdString().c_str());
      cvtColor(mtx2_color,mtx2,CV_RGB2GRAY);
      IplImage* img=new IplImage(mtx);
      QImage qimg=IplImage2QImage(img);
      ui->label_2->setPixmap(QPixmap::fromImage(qimg));

      IplImage* img2=new IplImage(mtx2);
      QImage qimg2=IplImage2QImage(img2);
      ui->label_3->setPixmap(QPixmap::fromImage(qimg2));
    }
  calcAdd(mtx,mtx2,&mtx_add);
  IplImage* img3=new IplImage(mtx_add);
  QImage qimg3=IplImage2QImage(img3);
  ui->label->setPixmap(QPixmap::fromImage(qimg3));
  setWindowTitle("Addition");
  show();
}

void Algebraic::substraction(Mat mtx,int trans)
{
  if(trans==0)
    {
#ifdef Q_WS_X11
      QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"/home/gsc/Documents",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));
#endif

#ifdef Q_WS_WIN
      QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));
#endif
      if (!fileName.isEmpty())
        {
          mtx2_color=imread(fileName.toStdString().c_str());
          cvtColor(mtx2_color,mtx2,CV_RGB2GRAY);

        }
      calcSub(mtx,mtx2,&mtx_sub);
    }
  else
    {
      mtx2=mtx.clone();
      for(int i=0;i<mtx.rows;i++)
        for(int j=0;j<mtx.cols;j++)
          {
            mtx2.at<uchar>(i,j)=mtx.at<uchar>(i-trans,j-trans);
          }
      calcSub(mtx,mtx2,&mtx_sub);
    }
  IplImage* img=new IplImage(mtx);
  QImage qimg=IplImage2QImage(img);
  ui->label_2->setPixmap(QPixmap::fromImage(qimg));

  IplImage* img2=new IplImage(mtx2);
  QImage qimg2=IplImage2QImage(img2);
  ui->label_3->setPixmap(QPixmap::fromImage(qimg2));
  IplImage* img3=new IplImage(mtx_sub);
  QImage qimg3=IplImage2QImage(img3);
  ui->label->setPixmap(QPixmap::fromImage(qimg3));
  setWindowTitle("Substraction");
  show();
}

void ImageDisplayer::on_action_Addition_triggered()
{
  this->add.addition(mtx);
}

void ImageDisplayer::on_action_Subtraction_triggered()
{
  this->sub.substraction(mtx,0);
}

void ImageDisplayer::on_action_Translation_triggered()
{
  this->sub.substraction(mtx,1);
}
