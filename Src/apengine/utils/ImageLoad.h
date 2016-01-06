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
		// ͼƬ��ʽ
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

		// ָ��ͼƬ��ָ��
		FIBITMAP *dib = nullptr;

		// ���ͼƬ��ʽ
		fif = FreeImage_GetFileType(filename, 0);

		// ����ʽλ�ã���������չ��ʽ�в²�
		if (fif == FIF_UNKNOWN)
		{
			fif = FreeImage_GetFIFFromFilename(filename);
		}

		// �����Ȼδ֪��ʽ�����ؿ�
		if (fif == FIF_UNKNOWN)
			return nullptr;

		// ����Ƿ�֧�ּ��ش˸�ʽ
		if (FreeImage_FIFSupportsReading(fif))
		{
			dib = FreeImage_Load(fif, filename);
		}

		// ���ܼ����򷵻ؿ�
		if (!dib)
		{
			return nullptr;
		}

		// ��ȡ����
		BYTE* result = FreeImage_GetBits(dib);

		// ��ȡͼƬ���
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return result;
	}
};