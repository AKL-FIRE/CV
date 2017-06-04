#include <opencv2/opencv.hpp>    
#include <iostream>  
  
using namespace cv;  
using namespace std;  
  
void intial(Mat src);  
void accbackgound(Mat src,Mat pre);  
void backgound(int count);  
void foregound(Mat src,Mat pre);  
void skin(Mat src);  
  
Mat bg,Th,mask0;  
Mat bglow0,bglow1,bglow2;  
Mat bghigh0,bghigh1,bghigh2;  
Mat mask;  
int high=10,low=10;  
  
int main()  
{  
    int count=0;  
    VideoCapture capture;  
    capture.open(0);  
    Mat fram,prefram,result,fg;  
    int framNum=0;  
  
  
    while(capture.isOpened())  
    {  
        capture>>fram;  
  
        fram.convertTo(fram,CV_32FC3);  
        normalize(fram,fram,1,0,CV_MINMAX);  
        imshow("src",fram);  
  
        if(framNum==0)  
        {  
            intial(fram);     
        }  
        else if(framNum<30)  
        {  
            ++count;  
            accbackgound(fram,prefram);  
        }  
        else if(framNum==30)  
            backgound(count);  
        else  
        {  
            foregound(fram,prefram);  
            skin(fram);  
        }  
        fram.copyTo(prefram);  
        framNum++;  
  
        char key=(char)waitKey(2);  
        switch(key)  
        {  
        case 27:  
            return 0;  
            break;  
              
        }  
    }  
}  
  
void intial(Mat src)  
{  
    src.copyTo(bg);  
}  
  
void accbackgound(Mat src,Mat pre)  
{  
    Mat temp;  
    accumulate(src,bg);  
    absdiff(src,pre,temp);  
      
    if (Th.data==NULL)  
    {  
        temp.copyTo(Th);  
    }  
    else  
        accumulate(temp,Th);  
}  
  
void backgound(int count)  
{  
    bg=bg/count;  
    Th=Th/count;  
      
    normalize(bg,bg,1,0,CV_MINMAX);  
    imshow("backgound",bg);   
  
    Mat t[3];  
    Mat b[3];  
    split(Th,t);  
    split(bg,b);  
    bglow0=b[0]-t[0]*low;  
    bglow1=b[1]-t[1]*low;  
    bglow2=b[2]-t[2]*low;  
    bghigh0=b[0]+t[0]*high;  
    bghigh1=b[1]+t[1]*high;  
    bghigh2=b[2]+t[2]*high;  
    cout<<"Start Traclking"<<endl;  
}  
  
void foregound(Mat src,Mat pre)  
{  
    Mat temp0,temp1,temp2;  
    Mat framNow[3];  
    Mat frampre[3];  
    framNow[0].setTo(Scalar(0,0,0));  
    framNow[1].setTo(Scalar(0,0,0));  
    framNow[2].setTo(Scalar(0,0,0));  
    temp0.setTo(Scalar(0,0,0));  
    temp1.setTo(Scalar(0,0,0));  
    temp2.setTo(Scalar(0,0,0));  
    /* 
    split(pre,frampre); 
    accumulateWeighted(frampre[0],bglow0,0.1); 
    accumulateWeighted(frampre[0],bghigh0,0.1); 
    accumulateWeighted(frampre[1],bglow1,0.1); 
    accumulateWeighted(frampre[1],bghigh1,0.1); 
    accumulateWeighted(frampre[2],bglow2,0.1); 
    accumulateWeighted(frampre[2],bglow2,0.1); 
    */  
    split(src,framNow);  
    inRange(framNow[0],bglow0,bghigh0,temp0);  
    inRange(framNow[1],bglow1,bghigh1,temp1);  
    inRange(framNow[2],bglow2,bghigh2,temp2);  
    bitwise_or(temp0,temp1,temp0);  
    bitwise_or(temp0,temp2,temp0);  
    bitwise_not(temp0,temp0);  
  
    imshow("Show",temp0);  
    temp0.copyTo(mask0);  
}  
  
void skin(Mat src)  
{  
    src.convertTo(src,CV_8UC3,255);  
    Mat yuv,dst;  
    cvtColor(src,yuv,CV_BGR2YCrCb);  
    Mat dstTemp1(src.rows, src.cols, CV_8UC1);  
    Mat dstTemp2(src.rows, src.cols, CV_8UC1);  
    // 对YUV空间进行量化，得到2值图像，亮的部分为手的形状  
    inRange(yuv, Scalar(0,133,0), Scalar(256,173,256), dstTemp1);  
    inRange(yuv, Scalar(0,0,77), Scalar(256,256,127), dstTemp2);  
    bitwise_and(dstTemp1, dstTemp2, mask);  
    dst.setTo(Scalar::all(0));  
      
    bitwise_and(mask,mask0,mask);  
    src.copyTo(dst,mask);  
  
    vector< vector<Point> > contours;   // 轮廓  
    vector< vector<Point> > filterContours; // 筛选后的轮廓  
    vector< Vec4i > hierarchy;    // 轮廓的结构信息  
    vector< Point > hull; // 凸包络的点集  
    contours.clear();  
    hierarchy.clear();  
    filterContours.clear();  
  
    // 得到手的轮廓  
    findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);  
            // 去除伪轮廓  
    for (size_t i = 0; i < contours.size(); i++)  
    {  
        //approxPolyDP(Mat(contours[i]), Mat(approxContours[i]), arcLength(Mat(contours[i]), true)*0.02, true);  
        if (fabs(contourArea(Mat(contours[i]))) > 1000&&fabs(arcLength(Mat(contours[i]),true))<2000)  //判断手进入区域的阈值  
        {  
            filterContours.push_back(contours[i]);  
        }  
    }  
    // 画轮廓  
    drawContours(src, filterContours, -1, Scalar(0,0,255), 2); //8, hierarchy);  
    imshow("traclking",src);  
}  