

#include"geometry.h"
#include<cmath>

void horiMirror(Mat mtx, Mat *mirror)
{
  Vec3b tempV;
  //int rows=mtx.rows;
  int cols=mtx.cols;
  *mirror=mtx.clone();
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        tempV=mtx.at<Vec3b>(i,cols-j);
        mirror->at<Vec3b>(i,j)=tempV;
      }
}

void vertMirror(Mat mtx, Mat *mirror)
{
  Vec3b tempV;
  int rows=mtx.rows;
  //int cols=mtx.cols;
  *mirror=mtx.clone();
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        tempV=mtx.at<Vec3b>(rows-i,j);
        mirror->at<Vec3b>(i,j)=tempV;
      }
}

void rotate(Mat mtx, Mat *rot, double theta)
{
  double a11=cos(theta* 0.0174532925);
  double a12=sin(theta* 0.0174532925);
  Mat T = (Mat_<double>(3,3) << a11,a12, 0, -a12, a11, 0, 0, 0, 1);
  *rot=mtx.clone();
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        rot->at<Vec3b>(i,j)[0]=0;
        rot->at<Vec3b>(i,j)[1]=0;
        rot->at<Vec3b>(i,j)[2]=0;
      }
  int rows=mtx.rows;
  int cols=mtx.cols;
  Mat flag(mtx.rows,mtx.cols,CV_8U);
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        flag.at<uchar>(i,j)=0;
      }

  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        Mat x=(Mat_<double>(1,3) << i,j, 1);
        Mat y(Mat::zeros(1,3,CV_64F));
        y=x*T;
        int v=round(y.at<double>(0,0));
        int w=round(y.at<double>(0,1));
        if(v<rows&&w<cols&&v>0&&w>0)
          {
            rot->at<Vec3b>(v,w)=mtx.at<Vec3b>(i,j);
            flag.at<uchar>(v,w)=1;
          }
      }

  for(int i=0;i<flag.rows;i++)
    for(int j=0;j<flag.cols;j++)
      {
        if(flag.at<uchar>(i,j)==0)
          {
            int x1,x2,y1,y2;
            x1=x2=rows;
            y1=y2=cols;
            for(int k=1;k<flag.rows-i;k++)
              {
                if(flag.at<uchar>(i+k,j)==1)
                  {
                    x2=k;break;
                  }
              }
            for(int k=1;k<i;k++)
              {
                if(flag.at<uchar>(i-k,j)==1)
                  {
                    x1=k;break;
                  }
              }
            for(int k=1;k<flag.cols-j;k++)
              {
                if(flag.at<uchar>(i,j+k)==1)
                  {
                    y2=k;break;
                  }
              }
            for(int k=1;k<j;k++)
              {
                if(flag.at<uchar>(i,j-k)==1)
                  {
                    y1=k;break;
                  }
              }
            int minx=min(x1,x2);
            int miny=min(y1,y2);
            int minv=min(minx,miny);
            if(minv==x1){rot->at<Vec3b>(i,j)=mtx.at<Vec3b>(i-minv,j);}
            else if(minv== x2){rot->at<Vec3b>(i,j)=rot->at<Vec3b>(i+minv,j);}
            else if(minv== y1){rot->at<Vec3b>(i,j)=rot->at<Vec3b>(i,j-minv);}
            else if(minv== y2){rot->at<Vec3b>(i,j)=rot->at<Vec3b>(i,j+minv);}

          }
      }
}

//Vec3b calcEmpty(Mat mtx, Mat flag, int rows, int cols)
//{
//  Vec3b a;
//  return a;
//}

void scale(Mat mtx, Mat *sca, double factorx,double factory)
{
  Mat T = (Mat_<double>(3,3) << factorx,0, 0,0, factory, 0, 0, 0, 1);


//  int multix=factorx+1;
//  int multiy=factory+1;
 // cout<<multi<<endl;
  //cout<<mtx.rows*multi<<' '<<mtx.cols*multi<<endl;
  *sca=Mat(int(mtx.rows*factorx)+1,int(mtx.cols*factory)+1,CV_8UC3);
  Mat flag(int(mtx.rows*factorx)+1,int(mtx.cols*factory)+1,CV_8U);
  for(int i=0;i<sca->rows;i++)
    for(int j=0;j<sca->cols;j++)
      {
        sca->at<Vec3b>(i,j)[0]=0;
        sca->at<Vec3b>(i,j)[1]=0;
        sca->at<Vec3b>(i,j)[2]=0;
      }
  int r0=mtx.rows;
  int c0=mtx.cols;
  int r1=sca->rows;
  int c1=sca->cols;
  double fr=(double)(r0-1)/(r1-1);
  double fc=(double)(c0-1)/(c1-1);



  int rows=sca->rows;
  int cols=sca->cols;
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
      {
        double x0=i*fr;
        double y0=j*fc;
        int x1=x0;
        int x2=x1+1;
        int y1=y0;
        int y2=y1+1;

        double fx1 = x0 - x1;
        double fx2 = 1.0f - fx1;
        double fy1 = y0 - y1;
        double fy2 = 1.0f - fy1;

        double s1 = fx1*fy1;
        double s2 = fx2*fy1;
        double s3 = fx2*fy2;
        double s4 = fx1*fy2;

        sca->at<Vec3b>(i,j)=mtx.at<Vec3b>(x2,y2)*s1+mtx.at<Vec3b>(x1,y2)*s2+mtx.at<Vec3b>(x1,y1)*s3+mtx.at<Vec3b>(x2,y1)*s4;
      }
}

double calcAngle(Mat mtx,int i,int j)
{
  return exp(-(pow((i-mtx.rows/2.0),2)+pow((j-mtx.cols/2.0),2))/(mtx.rows*mtx.cols))*0.0174532925;
}

void warp(Mat mtx, Mat *warp, double factor)
{
  *warp=mtx.clone();
  int rows=mtx.rows;
  int cols=mtx.cols;
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        warp->at<Vec3b>(i,j)[0]=0;
        warp->at<Vec3b>(i,j)[1]=0;
        warp->at<Vec3b>(i,j)[2]=0;
      }
  for(int i=0;i<mtx.rows;i++)
    for(int j=0;j<mtx.cols;j++)
      {
        double angle=calcAngle(mtx,i,j)*factor;

        //cout<<angle<<endl;
        int u=cos(angle)*(i-rows/2)+sin(angle)*(j-cols/2);
        int v=-sin(angle)*(i-rows/2)+cos(angle)*(j-cols/2);
        //cout<<u<<' '<<v<<endl;
        if(abs(u)<rows/2&&abs(v)<cols/2)
          {
            warp->at<Vec3b>(rows/2+u,cols/2+v)=mtx.at<Vec3b>(i,j);
          }
      }
}
