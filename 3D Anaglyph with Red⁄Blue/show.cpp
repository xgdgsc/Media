#include "show.h"
#include "ui_show.h"

Show::Show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show)
{
    ui->setupUi(this);
    connect(ui->ButtonSave,SIGNAL(clicked()),this,SLOT(saveImage()));
    setWindowTitle("Anaglyph");
    ui->label->setBackgroundRole(QPalette::Base);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);
    //ui->scrollArea->setWidget(ui->label);
}

Show::~Show()
{
    delete ui;
}

void Show::setAnaglyph(Mat mtx)
{
    show();
    mtx_anaglyph=mtx;
    IplImage* img=new IplImage(mtx_anaglyph);
    QImage qimg=IplImage2QImage(img);
    ui->label->setPixmap(QPixmap::fromImage(qimg));
}

void Show::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp *.jpeg *.tiff *.tif *.p?m *.sr *.jp2);;All Files (*.*);;BMP(*.bmp);;JPEG(*.jpg *.jpeg *.jp2);;PNG(*.png);;TIFF(*.tif *.tiff)"));
    if (!fileName.isEmpty())
    {
        imwrite(fileName.toStdString(),mtx_anaglyph);
        QMessageBox qmb;qmb.setText("Saved successfully!");qmb.exec();
    }
}
