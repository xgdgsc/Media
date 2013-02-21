#include <QtGui/QApplication>
#include "anaglyph.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Anaglyph w;
  w.show();
  
  return a.exec();
}
