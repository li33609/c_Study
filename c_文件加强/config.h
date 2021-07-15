#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// 配置信息的结构体
struct ConfigInfo
{
	char key[64];
	char value[64];
};

// 读取文件行数
int get_file_line(const char* file_path);

// 检测有效文件行数
int is_invalid_line(char* str);