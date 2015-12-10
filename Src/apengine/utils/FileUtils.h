#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <iostream>
#include <fstream>

// ��ȡ�ı��ļ�
class FileUtils
{
public:
	static std::string ReadFile(const char* filepath)
	{
		FILE * file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);  // �����ļ�����

		char* data = new char[length + 1];   // �����ڴ�

		memset(data, 0, length + 1);         // ����
		fseek(file, 0, SEEK_SET);			 // �ص��ļ�ͷ
		fread(data, 1, length, file);		 // ��ȡ�ļ�����

		fclose(file);
		std::string result(data);

		delete[] data;
		return result;
	}
};

#endif // ifn
