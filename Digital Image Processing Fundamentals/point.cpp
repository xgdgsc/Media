#include"point.h"


void calcHist(Mat img,int* result)
{
  for(int i=0;i<256;i++)
    {
      result[i]=0;
    }
  for(int i=0;i<img.rows;i++)
    for(int j=0;j<img.cols;j++)
      {
        result[img.at<uchar>(i,j)]++;
      }
}

void calcLinear(Mat img, Mat *Lt, double a, double b)
{
  *Lt=img.clone();
  for(int i=0;i<img.rows;i++)
    for(int j=0;j<img.cols;j++)
      {
        Lt->at<uchar>(i,j)=a*img.at<uchar>(i,j)+b;
      }
}

void calcAnti(Mat img_color, Mat *anti)
{
  *anti=img_color.clone();
  Vec3b tempV,tempA;
  int tempI[3];
  for(int i=0;i<img_color.rows;i++)
    for(int j=0;j<img_color.cols;j++)
      {
        tempV=img_color.at<Vec3b>(i,j);
        for(int k=0;k<3;k++)
          {
            tempI[k]=255-tempV[k];
            tempA[k]=tempI[k];
          }
        anti->at<Vec3b>(i,j)=tempA;
      }
}

void calcThreshold(Mat img, Mat *thr, int div)
{
  *thr=img.clone();
  for(int i=0;i<img.rows;i++)
    for(int j=0;j<img.cols;j++)
      {
        if(img.at<uchar>(i,j)>div)
          {
            thr->at<uchar>(i,j)=255;
          }
        else thr->at<uchar>(i,j)=0;
      }
}

void NormHist(Mat img, Mat *norm,int* histo,int* s)
{
  *norm=img.clone();
  calcHist(img,histo);
  calcS(img,histo,s);
  for(int i=0;i<img.rows;i++)
    for(int j=0;j<img.cols;j++)
      {
        //cout<<s[img.at<uchar>(i,j)]<<endl;
        norm->at<uchar>(i,j)=s[img.at<uchar>(i,j)];
      }
}

void calcS(Mat img,int *histo, int *res)
{
  int mn=img.cols*img.rows;
  int sum;
  for(int k=0;k<256;k++)
    {
      sum=0;
      for(int j=0;j<=k;j++)
        {
          sum+=histo[j];
        }
     // cout<<sum<<endl;
      res[k]=round((255.0/mn)*sum);
      //cout<<res[k]<<endl;
    }
}
