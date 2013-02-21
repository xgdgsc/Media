#include"algebraic.h"

void calcAdd(Mat mtx,Mat mtx2,Mat* add)
{
  *add=mtx.clone();
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        add->at<uchar>(i,j)= mtx.at<uchar>(i,j)+ mtx2.at<uchar>(i,j);
      }
}

void calcSub(Mat mtx, Mat mtx2, Mat *subs)
{
  *subs=mtx.clone();
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        subs->at<uchar>(i,j)= mtx.at<uchar>(i,j)- mtx2.at<uchar>(i,j);
      }
}
