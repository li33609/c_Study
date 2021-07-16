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

// 文件解析
void parse_file(const *file_path, int lines, struct ConfigInfo ** config_info);

// 根据key，获取value
char* get_value_by_key(char* key, struct ConfigInfo *config, int lines);

// 释放内存
void free_sapce(struct ConfigInfo* config_info);