#include "cv_lib.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include<vector>
using namespace std;
using namespace cv;



void loadimage()
{
	Mat img = imread("D:/Lenna.jpg");
	Mat img1;
	cvtColor(img, img1, COLOR_BGR2GRAY);

	imshow("test", img1);
	waitKey(0);
}


void _stdcall BGR2Gray(unsigned char* src, unsigned char* dst, int width, int height, int step)
{
	Mat img(height, width, CV_8UC3, src, step);
	Mat img1;

	cvtColor(img, img1, COLOR_BGR2GRAY);

	
	memcpy(dst, img1.data, sizeof(unsigned char) * img1.rows * img1.cols * img1.channels());
	
}



void _stdcall HistEqul(unsigned char* src, unsigned char* dst, int width, int height, int step)
{
	Mat img(height, width, CV_8UC1, src, step);
	Mat img1;
	equalizeHist(img, img1);

	memcpy(dst, img1.data, sizeof(unsigned char) * img1.rows * img1.cols * img1.channels());

}
//§äLINE

void _stdcall FindLine(unsigned char* src, unsigned char* dst, int width, int height, int step)
{
	Mat gray(height,width,CV_8UC1,src,step);
	Mat bw;
	
	adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("test", bw);
	Mat horizontal = bw.clone();
	Mat vertical = bw.clone();
	int horizontalsize = horizontal.cols / 30;
	// Create structure element for extracting horizontal lines through morphology operations
	Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalsize, 1));
	// Apply morphology operations
	erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
	dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));
	// Show extracted horizontal lines
	imshow("horizontal", horizontal);
}

void _stdcall Resize(unsigned char* src, unsigned char* dst, int width, int height, int step, int size)
{
	Mat img(height, width, CV_8UC3, src, step);
	Mat img1(size, size, CV_8UC3);
	resize(img, img1, Size(size, size));

	memcpy(dst, img1.data, sizeof(unsigned char) * img1.rows * img1.cols * img1.channels());

}


void _stdcall Dilation(unsigned char* src, int width,int height,int step,int size,int type)
{
	
	/*
	  cv::MORPH_RECT = 0,
	  cv::MORPH_CROSS = 1,
	  cv::MORPH_ELLIPSE = 2
	*/
	
	Mat img(height, width, CV_8UC3, src, step);


	Mat element = getStructuringElement(type,
		Size(2 * size + 1, 2 * size + 1),
		Point(size, size));

	dilate(img, img, element);

	memcpy(src, img.data, sizeof(unsigned char) * img.rows * img.cols * img.channels());


}

void _stdcall Erode(unsigned char* src, int width, int height, int step, int size, int type)
{

	/*
	  cv::MORPH_RECT = 0,
	  cv::MORPH_CROSS = 1,
	  cv::MORPH_ELLIPSE = 2
	*/

	Mat img(height, width, CV_8UC3, src, step);


	Mat element = getStructuringElement(type,
		Size(2 * size + 1, 2 * size + 1),
		Point(size, size));

	erode(img, img, element);

	memcpy(src, img.data, sizeof(unsigned char) * img.rows * img.cols * img.channels());


}

void _stdcall Blur(unsigned char* src, int width, int height, int step, int type, int blursize)
		{
			Mat img(height, width, CV_8UC3, src, step);

			
			Mat img1(height, width, CV_8UC3, step);
			/*
				type
				1 = average
				2 = gaussin
				3 = median
				4 = bilateral


			*/
			switch (type)
			{
			case 1:
				blur(img, img1, Size(blursize, blursize));
				break;
			case 2:
				GaussianBlur(img, img1, Size(blursize, blursize), 0);
				break;
			case 3:
				medianBlur(img, img1, blursize);
				break;
			case 4:
				bilateralFilter(img, img1, blursize, 50, 50);
				
				break;
			}

			memcpy(src, img1.data, sizeof(unsigned char) * img1.rows * img1.cols * img1.channels());
		}


void _stdcall Morphology_Operate(unsigned char* src ,int width,int height,int step,int morph_operator,int type,int size)
{
	/*
	«I»k:0
	¿±µÈ:1
	¶}¹õ¦¡¡GMORPH_OPEN¡G2
	Ãö³¬¡GMORPH_CLOSE¡G3
	º¥ÅÜ¡GMORPH_GRADIENT¡G4
	³»´U¡GMORPH_TOPHAT¡G5
	¶Â´U¤l¡GMORPH_BLACKHAT¡G6*/



	/*
	type 
	MORPH_RECT:0
	MORPH_CROSS:1
	MORPH_ELLIPSE:2


	*/
	Mat img(height, width, CV_8UC3, src, step);


	Mat img1(height, width, CV_8UC3, step);
	
	// MORPH_X : 2,3,4,5 and 6
	int operation = morph_operator ;
	Mat element = getStructuringElement(type, Size(size , size ), Point(-1,-1));
	morphologyEx(img, img1, operation, element);

	memcpy(src, img1.data, sizeof(unsigned char) * img1.rows * img1.cols * img1.channels());

	
}