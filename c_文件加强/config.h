#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// ������Ϣ�Ľṹ��
struct ConfigInfo
{
	char key[64];
	char value[64];
};

// ��ȡ�ļ�����
int get_file_line(const char* file_path);

// �����Ч�ļ�����
int is_invalid_line(char* str);