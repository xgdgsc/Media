#ifndef QWTDIALOG_H
#define QWTDIALOG_H

#include <QDialog>

#include<qwt/qwt_plot.h>
#include<qwt/qwt_plot_curve.h>
#include<qwt/qwt_plot_histogram.h>
#include<qwt/qwt_series_data.h>
#include<iostream>

namespace Ui {
  class qwtdialog;
}

class qwtdialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit qwtdialog(QWidget *parent = 0);
  ~qwtdialog();
  void showPlot(int histo[]);
private:
  Ui::qwtdialog *ui;
};

#endif // QWTDIALOG_H
