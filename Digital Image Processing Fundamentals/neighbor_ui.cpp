#include "neighbor_ui.h"
#include "ui_neighbor.h"
#include"fundamental.h"

Neighbor::Neighbor(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Neighbor)
{
  ui->setupUi(this);
  connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(updateCanny()));
  connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->label_4,SLOT(setNum(int)));
  setWindowTitle("Edge Detection");
}

Neighbor::~Neighbor()
{
  delete ui;
}

void Neighbor::edgeDetection(Mat mtx, string method)
{
  ui->label_3->hide();
  ui->label_4->hide();
  ui->horizontalSlider->hide();
  show();
  this->mtx=mtx;
  calcEdge(mtx,&mtx_edge,method);
  showEdge();
}

void Neighbor::edgeCanny(Mat mtx)
{
  ui->label_3->show();
  ui->label_4->show();
  ui->horizontalSlider->show();
  show();
  this->mtx=mtx;
  calcCanny(mtx,&mtx_edge,ui->horizontalSlider->value());
  showEdge();
}

void Neighbor::updateCanny()
{
  calcCanny(mtx,&mtx_edge,ui->horizontalSlider->value());
  showEdge();
}

void Neighbor::showEdge()
{
  IplImage* img=new IplImage(mtx);
  IplImage* img_edge=new IplImage(mtx_edge);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_edge=IplImage2QImage(img_edge);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_edge));
  repaint();
}

void Neighbor::neighborSmooth(Mat mtx)
{
  this->mtx=mtx;
  smoothNeighbor(mtx,&mtx_smooth);
  showSmooth();
}

void Neighbor::gaussianSmooth(Mat mtx)
{
  this->mtx=mtx;
  smoothGaussian(mtx,&mtx_smooth);
  showSmooth();
}

void Neighbor::medianSmooth(Mat mtx)
{
  this->mtx=mtx;
  smoothMedian(mtx,&mtx_smooth);
  showSmooth();
}

void Neighbor::showSmooth()
{
  ui->label_3->hide();
  ui->label_4->hide();
  ui->horizontalSlider->hide();
  show();
  IplImage* img=new IplImage(mtx);
  IplImage* img_smooth=new IplImage(mtx_smooth);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_smooth=IplImage2QImage(img_smooth);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_smooth));
  repaint();
}

void ImageDisplayer::on_actionRobert_triggered()
{
  nb.edgeDetection(mtx_color,"Robert");
}

void ImageDisplayer::on_action_Prewitt_triggered()
{
  nb.edgeDetection(mtx_color,"Prewitt");
}

void ImageDisplayer::on_action_Sobel_triggered()
{
  nb.edgeDetection(mtx_color,"Sobel");
}

void ImageDisplayer::on_action_Canny_triggered()
{
  nb.edgeCanny(mtx_color);
}

void ImageDisplayer::on_action_Neighborhood_averaging_triggered()
{
  nb.neighborSmooth(mtx_color);
}

void ImageDisplayer::on_action_Gaussian_Filter_triggered()
{
  nb.gaussianSmooth(mtx_color);
}

void ImageDisplayer::on_action_Median_Filter_triggered()
{
  nb.medianSmooth(mtx_color);
}
