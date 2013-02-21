
#include"fundamental.h"

void ImageDisplayer::on_actionHistogram_triggered()
{
  calcHist(mtx,histo);
  qwtd.showPlot(histo);
}

void ImageDisplayer::on_action_Linear_Transformation_triggered()
{
  this->lt.showLinearTrans(mtx);
}

void ImageDisplayer::on_action_Anti_color_Image_triggered()
{
  atc.anti(mtx_color);
}

void ImageDisplayer::on_action_Threshold_triggered()
{
  thd.showThrehold(mtx);
}

void ImageDisplayer::on_actionHistogram_Normalization_triggered()
{
  htn.normHisto(mtx);
}

