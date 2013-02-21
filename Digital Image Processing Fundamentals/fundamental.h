#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H

#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<iomanip>

#include<QtOpenGL/QtOpenGL>
#include<QtDebug>
#include<QString>
#include<QFileDialog>
#include<GL/glu.h>
#include<QShortcut>
#include<QImage>
#include<QIcon>
#include<QStyle>
#include<QCommonStyle>

#include<opencv2/opencv.hpp>



#include"libs.h"
#include"ui_mainwindow.h"
#include"point.h"
#include"qwtdialog.h"
#include"lineartrans.h"
#include"anticolor.h"
#include"threhold.h"
#include"histonorm.h"
#include"algebraic_ui.h"
#include"geometry_ui.h"
#include"affine.h"
#include"morphological_ui.h"
#include"neighbor_ui.h"
#include"report.h"

using namespace std;
using namespace cv;
namespace Ui{
  class ImageDisplayer;
}
class ImageDisplayer:public QMainWindow
{
  Q_OBJECT

public:
  explicit ImageDisplayer(QWidget *parent =0);
  ~ImageDisplayer();
  void Display();
public:
   Mat mtx,mtx_color;
  IplImage *img;
  int histo[256];
  Geometry horizontal,vertical;
  affine aff;
  QString Evaluation2Dblocks;
  Mat M88iDCT;
  Mat M88iDCT_Q;
  vector<Mat> M88DCT;
  QImage ImageBlocks;
public:
  QString get2DblocksTime();
public slots:
  void loadImage();
  void on_actionOpen_triggered();
  void on_actionExit_triggered();
  void on_action_About_triggered();
  void on_actionZoom_In_triggered();
  void on_actionZoom_Out_triggered();
  void on_action_Fit_to_Window_triggered();
  void on_action_Actual_Size_triggered();
  void on_actionGenerate_triggered();
  void on_actionHistogram_triggered();
  void on_action_Linear_Transformation_triggered();
  void on_action_Anti_color_Image_triggered();
  void on_action_Threshold_triggered();
  void on_actionHistogram_Normalization_triggered();
  void on_action_Addition_triggered();
  void on_action_Subtraction_triggered();
  void on_action_Translation_triggered();
  void on_action_Horizontal_Mirror_triggered();
  void on_action_Vertical_Mirror_triggered();
  void on_action_Affine_Transformation_triggered();
  void on_action_Erosion_triggered();
  void on_action_Dilation_triggered();
  void on_action_Open_Operation_triggered();
  void on_action_Close_Operation_triggered();
  void on_action_Thinning_triggered();
  void on_actionRobert_triggered();
  void on_action_Sobel_triggered();
  void on_action_Canny_triggered();
  void on_action_Prewitt_triggered();
  void on_action_Neighborhood_averaging_triggered();
  void on_action_Gaussian_Filter_triggered();
  void on_action_Median_Filter_triggered();
  void on_action2DDCT_by_8_8_blocks_report_triggered();
  void Inverse_2D_blocks_DCT(int coefficient);
private:
  Ui::ImageDisplayer *ui;
  QLabel *imageLabel;
  QScrollArea *scrollArea;
  QCommonStyle  qcs;
  qwtdialog qwtd;
  linearTrans lt;
  anticolor atc;
  threhold thd;
  histonorm htn;
  Algebraic add,sub;
  Morphological mp;
  Neighbor nb;
  Report rpt2Dblocks;
private:
  void initializeShortcuts();
  void initializeWidgets();
  void initializeIcons();
  void fitToWindow();
  void normalSize();
  void updateActions();
  void scaleImage(double factor);
  void adjustScrollBar(QScrollBar* scrollBar, double factor);
  void zoomIn();
  void zoomOut();
  double scaleFactor;

protected:
  //  void initializeGL();
  //  void resizeGL(int w, int h);
  //  void paintGL();
};

#endif // FUNDAMENTAL_H
