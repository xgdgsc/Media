#ifndef NEIGHBOR_UI_H
#define NEIGHBOR_UI_H

#include <QDialog>
#include<QFileDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<opencv2/opencv.hpp>
#include<iostream>
#include"neighbor.h"

using namespace std;
using namespace cv;

namespace Ui {
  class Neighbor;
}

class Neighbor : public QDialog
{
  Q_OBJECT

public:
  explicit Neighbor(QWidget *parent = 0);
  ~Neighbor();
  void edgeDetection(Mat mtx,string method);
  void edgeCanny(Mat mtx);
  void neighborSmooth(Mat mtx);
  void gaussianSmooth(Mat mtx);
  void medianSmooth(Mat mtx);
  void showEdge();
  void showSmooth();
  Mat mtx,mtx_edge,mtx_smooth;
public slots:
  void updateCanny();
private:
  Ui::Neighbor *ui;
};

#endif // NEIGHBOR_UI_H
