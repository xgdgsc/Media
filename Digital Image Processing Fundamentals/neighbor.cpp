#include"neighbor.h"
void calcEdge(Mat mtx, Mat *edge, string method)
{
  Vec3b gx,gy,M;
  *edge=mtx.clone();
  if(method=="Robert")
    {
      for(int i=0;i<mtx.rows-1;i++)
        for(int j=0;j<mtx.cols-1;j++)
          {
            gx=mtx.at<Vec3b>(i+1,j+1)-mtx.at<Vec3b>(i,j);
            gy=mtx.at<Vec3b>(i+1,j)-mtx.at<Vec3b>(i,j+1);

            for(int k=0;k<3;k++)
              {
                M[k]=abs(gx[k])+abs(gy[k]);
              }
            edge->at<Vec3b>(i,j)=M;
          }
    }
  else if(method=="Sobel")
    {
      for(int i=1;i<mtx.rows-1;i++)
        for(int j=1;j<mtx.cols-1;j++)
          {
            gx=mtx.at<Vec3b>(i+1,j-1)+2*mtx.at<Vec3b>(i+1,j)+mtx.at<Vec3b>(i+1,j+1)
                -(mtx.at<Vec3b>(i-1,j-1)+2*mtx.at<Vec3b>(i-1,j)+mtx.at<Vec3b>(i-1,j+1));
            gy=mtx.at<Vec3b>(i-1,j+1)+2*mtx.at<Vec3b>(i,j+1)+mtx.at<Vec3b>(i+1,j+1)
                -(mtx.at<Vec3b>(i-1,j-1)+2*mtx.at<Vec3b>(i,j-1)+mtx.at<Vec3b>(i+1,j-1));
            for(int k=0;k<3;k++)
              {
                M[k]=abs(gx[k])+abs(gy[k]);
              }
            edge->at<Vec3b>(i,j)=M;
          }
    }
  else if(method=="Prewitt")
    {
      for(int i=1;i<mtx.rows-1;i++)
        for(int j=1;j<mtx.cols-1;j++)
          {
            gx=mtx.at<Vec3b>(i+1,j-1)+mtx.at<Vec3b>(i+1,j)+mtx.at<Vec3b>(i+1,j+1)
                -(mtx.at<Vec3b>(i-1,j-1)+mtx.at<Vec3b>(i-1,j)+mtx.at<Vec3b>(i-1,j+1));
            gy=mtx.at<Vec3b>(i-1,j+1)+mtx.at<Vec3b>(i,j+1)+mtx.at<Vec3b>(i+1,j+1)
                -(mtx.at<Vec3b>(i-1,j-1)+mtx.at<Vec3b>(i,j-1)+mtx.at<Vec3b>(i+1,j-1));
            for(int k=0;k<3;k++)
              {
                M[k]=abs(gx[k])+abs(gy[k]);
              }
            edge->at<Vec3b>(i,j)=M;
          }
    }
}

void calcCanny(Mat mtx, Mat *edge,int lowThreshold)
{
  int ratio = 3;
  int kernel_size = 3;
  Mat mtx_gray,detected_edges;
  cvtColor(mtx,mtx_gray,CV_RGB2GRAY);
  blur( mtx_gray, detected_edges, Size(3,3) );
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
  Mat dst;
  dst = Scalar::all(0);
  mtx.copyTo(dst, detected_edges);
  *edge=detected_edges;
}

void smoothNeighbor(Mat mtx, Mat *smooth)
{
  *smooth=mtx.clone();
  for(int i=1;i<mtx.rows-1;i++)
    for(int j=1;j<mtx.cols-1;j++)
      {
         Vec3b tempV;
        int sum[3];
        for(int k=0;k<3;k++)
          {
            sum[k]=0;
          }
        for(int a=-1;a<=1;a++)
          for(int b=-1;b<=1;b++)
            {
              tempV=mtx.at<Vec3b>(i+a,j+b);
              for(int k=0;k<3;k++)
                {
                  sum[k]+=tempV[k];
                }
            }
        for(int k=0;k<3;k++)
          {
            sum[k]=sum[k]/9.0;
            tempV[k]=sum[k];
          }
        smooth->at<Vec3b>(i,j)=tempV;
      }
}

void smoothGaussian(Mat mtx, Mat *smooth)
{
  *smooth=mtx.clone();
  for(int i=2;i<mtx.rows-2;i++)
    for(int j=2;j<mtx.cols-2;j++)
      {
         Vec3b tempV;
        int sum[3];
        for(int k=0;k<3;k++)
          {
            sum[k]=0;
          }
        for(int a=-2;a<=2;a++)
          for(int b=-2;b<=2;b++)
            {
              tempV=mtx.at<Vec3b>(i+a,j+b);
              for(int k=0;k<3;k++)
                {
                  if(abs(a)==2&&abs(b)==2)
                    {sum[k]+=tempV[k];}
                  else if((abs(a)==2&&abs(b)==1)||(abs(a)==1&&abs(b)==2))
                    {sum[k]+=4*tempV[k];}
                  else if((abs(a)==2&&abs(b)==0)||(abs(a)==0&&abs(b)==2))
                    {sum[k]+=7*tempV[k];}
                  else if(abs(a)==1&&abs(b)==1)
                    {sum[k]+=16*tempV[k];}
                  else if((abs(a)==1&&abs(b)==0)||(abs(a)==0&&abs(b)==1))
                    {sum[k]+=26*tempV[k];}
                  else if(a==0&&b==0)
                    {sum[k]+=41*tempV[k];}
                }
            }
        for(int k=0;k<3;k++)
          {
            sum[k]=sum[k]/273;
            tempV[k]=sum[k];
          }
        smooth->at<Vec3b>(i,j)=tempV;
      }
}

void smoothMedian(Mat mtx, Mat *smooth)
{
  *smooth=mtx.clone();
  for(int i=1;i<mtx.rows-1;i++)
    for(int j=1;j<mtx.cols-1;j++)
      {
         Vec3b tempV;
        vector<int> order[3];

        for(int a=-1;a<=1;a++)
          for(int b=-1;b<=1;b++)
            {
              tempV=mtx.at<Vec3b>(i+a,j+b);
              for(int k=0;k<3;k++)
                {
                  order[k].push_back(tempV[k]);
                }
            }

        for(int k=0;k<3;k++)
          {
            sort(order[k].begin(),order[k].end());
            tempV[k]=order[k][5];
          }
        smooth->at<Vec3b>(i,j)=tempV;
      }
}
