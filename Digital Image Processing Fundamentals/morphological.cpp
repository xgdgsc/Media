

#include"morphological.h"
#include"point.h"

void erosion(Mat mtx, Mat *mtx_bin,Mat *mtx_ero)
{
  calcThreshold(mtx,mtx_bin,128);
  erosion(mtx_bin,mtx_ero);
}

void erosion(Mat *mtx_bin, Mat *mtx_ero)
{
  *mtx_ero=mtx_bin->clone();
  for(int i=1;i<mtx_bin->rows-1;i++)
    for(int j=1;j<mtx_bin->cols-1;j++)
      {
        if(mtx_bin->at<uchar>(i-1,j-1)==255
           &&mtx_bin->at<uchar>(i-1,j)==255
           &&mtx_bin->at<uchar>(i-1,j+1)==255
           &&mtx_bin->at<uchar>(i,j-1)==255
           &&mtx_bin->at<uchar>(i,j)==255
           &&mtx_bin->at<uchar>(i,j+1)==255
           &&mtx_bin->at<uchar>(i+1,j-1)==255
           &&mtx_bin->at<uchar>(i+1,j)==255
           &&mtx_bin->at<uchar>(i+1,j+1)==255)
          {
            mtx_ero->at<uchar>(i,j)=255;
          }
        else
          {
            mtx_ero->at<uchar>(i,j)=0;
          }
      }
}


void dilation(Mat mtx, Mat *mtx_bin,Mat *mtx_dil)
{
  calcThreshold(mtx,mtx_bin,128);
  dilation(mtx_bin,mtx_dil);
}

void dilation(Mat *mtx_bin, Mat *mtx_dil)
{
  *mtx_dil=mtx_bin->clone();
  for(int i=1;i<mtx_bin->rows-1;i++)
    for(int j=1;j<mtx_bin->cols-1;j++)
      {
        if(mtx_bin->at<uchar>(i-1,j-1)==0
           &&mtx_bin->at<uchar>(i-1,j)==0
           &&mtx_bin->at<uchar>(i-1,j+1)==0
           &&mtx_bin->at<uchar>(i,j-1)==0
           &&mtx_bin->at<uchar>(i,j)==0
           &&mtx_bin->at<uchar>(i,j+1)==0
           &&mtx_bin->at<uchar>(i+1,j-1)==0
           &&mtx_bin->at<uchar>(i+1,j)==0
           &&mtx_bin->at<uchar>(i+1,j+1)==0)
          {
            mtx_dil->at<uchar>(i,j)=0;
          }
        else
          {
            mtx_dil->at<uchar>(i,j)=255;
          }
      }
}
int calcA(Mat *mtx_bin,int i,int j)
{
  int order[9]=
  {
    mtx_bin->at<uchar>(i,j),
    mtx_bin->at<uchar>(i-1,j),
    mtx_bin->at<uchar>(i-1,j+1),
    mtx_bin->at<uchar>(i,j+1),
    mtx_bin->at<uchar>(i+1,j+1),
    mtx_bin->at<uchar>(i+1,j),
    mtx_bin->at<uchar>(i+1,j-1),
    mtx_bin->at<uchar>(i,j-1),
    mtx_bin->at<uchar>(i-1,j-1)
  };
  int n=0;
  for(int k=1;k<9;k++)
    {
      if(order[k]==0&&order[k+1]==255)
        {n++;}
    }
  return n;
}

void thinning(Mat mtx,Mat *mtx_bin, Mat *mtx_thin)
{
  calcThreshold(mtx,mtx_bin,128);
  *mtx_thin=mtx_bin->clone();
  int N;
  for(int i=1;i<mtx_bin->rows-1;i++)
    for(int j=1;j<mtx_bin->cols-1;j++)
      {
        N=0;
        for(int a=-1;a<=1;a++)
          for(int b=-1;b<=1;b++)
            {
              if(mtx_bin->at<uchar>(i+a,j+b)==0)
                {N++;}
            }
        int A=calcA(mtx_bin,i,j);
        if(
           N>=2&&N<=6
           &&A==1
           &&mtx_bin->at<uchar>(i-1,j)*mtx_bin->at<uchar>(i,j+1)*mtx_bin->at<uchar>(i+1,j)==0
           &&mtx_bin->at<uchar>(i,j+1)*mtx_bin->at<uchar>(i+1,j)*mtx_bin->at<uchar>(i,j-1)==0
           )
          {
            mtx_thin->at<uchar>(i,j)=0;
          }
      }
}
