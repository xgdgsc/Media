#include "affine.h"
#include "ui_affine.h"
#include"geometry.h"
#include"libs.h"

affine::affine(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::affine)
{
  ui->setupUi(this);
  connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(showRotate()));
  connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->label_4,SLOT(setNum(int)));
  connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(showScale()));
  connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->label_5,SLOT(setNum(int)));
  connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(showScale()));
  connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),ui->label_7,SLOT(setNum(int)));
  connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(showWarp()));
  connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),ui->label_9,SLOT(setNum(int)));
}

affine::~affine()
{
  delete ui;
}

void affine::showAffine(Mat mtx)
{
  setWindowTitle("Affine Transformation");
  this->mtx=mtx;
  show();
}

void affine::showRotate()
{
  int theta=ui->horizontalSlider->value();
  rotate(mtx,&mtx_rot,theta);
  IplImage* img=new IplImage(mtx_rot);
  QImage qmtx=IplImage2QImage(img);
  ui->label->clear();
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  repaint();
}

void affine::showScale()
{
  double factorx=ui->horizontalSlider_2->value()/10.0;
  double factory=ui->horizontalSlider_3->value()/10.0;
  //cout<<factorx<<' '<<factory<<endl;
  scale(mtx,&mtx_sca,factorx,factory);

  IplImage* img=new IplImage(mtx_sca);
  QImage qmtx=IplImage2QImage(img);
  ui->label->clear();
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  repaint();
}

void affine::showWarp()
{
  warp(mtx,&mtx_warp,ui->horizontalSlider_4->value());
  IplImage* img=new IplImage(mtx_warp);
  QImage qmtx=IplImage2QImage(img);
  ui->label->clear();
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  repaint();
}
