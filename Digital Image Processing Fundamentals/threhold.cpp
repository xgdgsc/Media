#include "threhold.h"
#include "ui_threhold.h"

threhold::threhold(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::threhold)
{
  ui->setupUi(this);
  ui->label_2->setBackgroundRole(QPalette::Base);
  ui->label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_2->setScaledContents(true);
  ui->label_3->setBackgroundRole(QPalette::Base);
  ui->label_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->label_3->setScaledContents(true);
  connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(showThrehold()));
}

threhold::~threhold()
{
  delete ui;
}

void threhold::showThrehold(Mat mtx)
{
  this->mtx=mtx;
  show();
}

void threhold::showThrehold()
{
  int div=ui->lineEdit->text().toInt();
  calcThreshold(mtx,&mtx_thr,div);
  IplImage* img=new IplImage(mtx);
  IplImage* img_thr=new IplImage(mtx_thr);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_thr=IplImage2QImage(img_thr);
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_3->setPixmap(QPixmap::fromImage(qmtx_thr));
  repaint();
}
