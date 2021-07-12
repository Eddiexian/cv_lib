#pragma once
#ifndef _CV_LIB_H
#define _CV_LIB_H

#ifdef IMAGE_EXPORTS

#define IMAGE_API __declspec(dllexport)
#else 

#define IMAGE_API __declspec(dllimport)

#endif

extern "C" IMAGE_API  void loadimage();

extern "C" IMAGE_API  void _stdcall BGR2Gray(unsigned char* src, unsigned char* dst, int width, int height, int step);

extern "C" IMAGE_API void _stdcall HistEqul(unsigned char* src, unsigned char* dst, int width, int height, int step);


extern "C" IMAGE_API void _stdcall FindLine(unsigned char* src, unsigned char* dst, int width, int height, int step);

extern "C" IMAGE_API void _stdcall Resize(unsigned char* src, unsigned char* dst,int width, int height, int step, int size);

extern "C" IMAGE_API  void _stdcall Blur(unsigned char* src, int width, int height, int step,int type,int blursize);

extern "C" IMAGE_API  void _stdcall Dilation(unsigned char* src, int width, int height, int step, int size, int type);

extern "C" IMAGE_API  void _stdcall Erode(unsigned char* src, int width, int height, int step, int size, int type);

extern "C" IMAGE_API void _stdcall Morphology_Operate(unsigned char* src, int width, int height, int step, int morph_operator, int type, int size);

#endif