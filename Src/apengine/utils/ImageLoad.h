#pragma once
#pragma once

#include "gl/glew.h"
#include <string>
#include "freeimage.h"

class ImageUtils
{
public:
	static BYTE* load_image(const char* filename, GLsizei* width, GLsizei* height)
	{
		// 图片格式
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

		// 指向图片的指针
		FIBITMAP *dib = nullptr;

		// 检查图片格式
		fif = FreeImage_GetFileType(filename, 0);

		// 若格式位置，尝试在扩展格式中猜测
		if (fif == FIF_UNKNOWN)
		{
			fif = FreeImage_GetFIFFromFilename(filename);
		}

		// 如果仍然未知格式，返回空
		if (fif == FIF_UNKNOWN)
			return nullptr;

		// 检测是否支持加载此格式
		if (FreeImage_FIFSupportsReading(fif))
		{
			dib = FreeImage_Load(fif, filename);
		}

		// 不能加载则返回空
		if (!dib)
		{
			return nullptr;
		}

		// 获取数据
		BYTE* result = FreeImage_GetBits(dib);

		// 获取图片宽高
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return result;
	}
};