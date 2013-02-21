#include "qwtdialog.h"
#include "ui_qwtdialog.h"
using namespace std;


qwtdialog::qwtdialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::qwtdialog)
{
  ui->setupUi(this);
  //show();
}

qwtdialog::~qwtdialog()
{
  delete ui;
}

void qwtdialog::showPlot(int histo[256])
{

  QwtPlotHistogram histoPlot;
  //  int bin[256];
  //  for(int i=0;i<256;i++)
  //    {
  //     // bin[i]=i;
  //      cout<<histo[i]<<endl;
  //    }

  QVector<QwtIntervalSample> samples(256);

  for ( uint i = 0; i < 256; i++ )
    {
      QwtInterval interval(double(i), i + 1.0);
      interval.setBorderFlags(QwtInterval::ExcludeMaximum);
      samples[i] = QwtIntervalSample(histo[i], interval);
    }
  histoPlot.setData(new QwtIntervalSeriesData(samples));
  //histoPlot.setSamples(samples);

  histoPlot.attach(ui->qwtPlot);
  histoPlot.setStyle(QwtPlotHistogram::Columns);
  this->setWindowTitle("Histogram");
  ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString("gray steps"));

  ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("number of points"));
  show();
  ui->qwtPlot->replot();
  repaint();
}
