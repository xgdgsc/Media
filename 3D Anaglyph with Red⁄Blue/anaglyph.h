#ifndef ANAGLYPH_H
#define ANAGLYPH_H

#include <QDialog>

#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<iomanip>


#include<QtDebug>
#include<QString>
#include<QFileDialog>

#include<QShortcut>
#include<QImage>
#include<QIcon>
#include<QStyle>
#include<QCommonStyle>

#include<opencv2/opencv.hpp>
#include"libs.h"
#include"show.h"

using namespace std;
using namespace cv;

namespace Ui {
  class Anaglyph;
}

class Anaglyph : public QDialog
{
  Q_OBJECT
  
public:
  explicit Anaglyph(QWidget *parent = 0);
  ~Anaglyph();

public slots:
  void loadLeft();
  void loadRight();
  void generateAnaglyph();
private:
  Show showAnaglyph;
  Mat mtx_left,mtx_right,mtx_anaglyph;
  Ui::Anaglyph *ui;
};

#endif // ANAGLYPH_H
