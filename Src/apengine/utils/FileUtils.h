#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <iostream>
#include <fstream>

// 读取文本文件
class FileUtils
{
public:
	static std::string ReadFile(const char* filepath)
	{
		FILE * file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);  // 计算文件长度

		char* data = new char[length + 1];   // 分配内存

		memset(data, 0, length + 1);         // 清零
		fseek(file, 0, SEEK_SET);			 // 回到文件头
		fread(data, 1, length, file);		 // 读取文件内容

		fclose(file);
		std::string result(data);

		delete[] data;
		return result;
	}
};

#endif // ifn
