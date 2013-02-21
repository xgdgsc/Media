#include "histonorm.h"
#include "ui_histonorm.h"

histonorm::histonorm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::histonorm)
{
  ui->setupUi(this);

    ui->label->setBackgroundRole(QPalette::Base);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);
    ui->label_2->setBackgroundRole(QPalette::Base);
    ui->label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_2->setScaledContents(true);
}

histonorm::~histonorm()
{
  delete ui;
}

void histonorm::normHisto(Mat mtx)
{
  show();
  NormHist(mtx,&mtx_norm,histo,s);
  IplImage* img=new IplImage(mtx);
  IplImage* img_norm=new IplImage(mtx_norm);
  QImage qmtx=IplImage2QImage(img);
  QImage qmtx_norm=IplImage2QImage(img_norm);
  ui->label->setPixmap(QPixmap::fromImage(qmtx));
  ui->label_2->setPixmap(QPixmap::fromImage(qmtx_norm));

  QwtPlotHistogram histoPlot;
  QVector<QwtIntervalSample> samples(256);
  for ( uint i = 0; i < 256; i++ )
    {
      QwtInterval interval(double(i), i + 1.0);
      interval.setBorderFlags(QwtInterval::ExcludeMaximum);
      samples[i] = QwtIntervalSample(histo[i], interval);
    }
  histoPlot.setData(new QwtIntervalSeriesData(samples));
  histoPlot.attach(ui->qwtPlot);
  ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString("gray steps"));
  ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("number of points"));
  ui->qwtPlot->replot();

  int histo2[256];
  calcHist(mtx_norm,histo2);
  QwtPlotHistogram histoPlot2;
  QVector<QwtIntervalSample> samples2(256);
  for ( uint i = 0; i < 256; i++ )
    {
      QwtInterval interval(double(i), i + 1.0);
      interval.setBorderFlags(QwtInterval::ExcludeMaximum);
      samples2[i] = QwtIntervalSample(histo2[i], interval);
    }
  histoPlot2.setData(new QwtIntervalSeriesData(samples2));
  histoPlot2.attach(ui->qwtPlot_2);
  ui->qwtPlot_2->setAxisTitle(QwtPlot::xBottom,QString("gray steps"));
  ui->qwtPlot_2->setAxisTitle(QwtPlot::yLeft,QString("number of points"));
  ui->qwtPlot_2->replot();
  repaint();
}

