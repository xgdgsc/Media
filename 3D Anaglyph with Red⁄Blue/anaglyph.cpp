#include "anaglyph.h"
#include "ui_anaglyph.h"

Anaglyph::Anaglyph(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Anaglyph)
{
  ui->setupUi(this);
  connect(ui->ButtonLeft,SIGNAL(clicked()),this,SLOT(loadLeft()));
  connect(ui->ButtonRight,SIGNAL(clicked()),this,SLOT(loadRight()));
  connect(ui->ButtonGenerate,SIGNAL(clicked()),this,SLOT(generateAnaglyph()));
  ui->label_left->setBackgroundRole(QPalette::Base);
  ui->label_left->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_left->setScaledContents(true);
  ui->label_right->setBackgroundRole(QPalette::Base);
  ui->label_right->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_right->setScaledContents(true);
}

Anaglyph::~Anaglyph()
{
  delete ui;
}

void Anaglyph::loadLeft()
{
  QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));

  if (!fileName.isEmpty())
    {
      mtx_left=imread(fileName.toStdString(),1);
      IplImage* img=new IplImage(mtx_left);
      QImage qimg=IplImage2QImage(img);
      ui->label_left->setPixmap(QPixmap::fromImage(qimg));
    }
}

void Anaglyph::loadRight()
{
  QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));

  if (!fileName.isEmpty())
    {
      mtx_right=imread(fileName.toStdString(),1);
      IplImage* img=new IplImage(mtx_right);
      QImage qimg=IplImage2QImage(img);
      ui->label_right->setPixmap(QPixmap::fromImage(qimg));
    }
  if (mtx_left.size!=mtx_right.size)
    {
      QMessageBox qmb;qmb.setText("Please choose two images of the same size!");qmb.exec();
      loadRight();
    }
}

void Anaglyph::generateAnaglyph()
{
  deleteBGchannel(&mtx_left);
  deleteRchannel(&mtx_right);
  mtx_anaglyph=mtx_left+mtx_right;
  showAnaglyph.setAnaglyph(mtx_anaglyph);
}
