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

// �ļ�����
void parse_file(const *file_path, int lines, struct ConfigInfo ** config_info);

// ����key����ȡvalue
char* get_value_by_key(char* key, struct ConfigInfo *config, int lines);

// �ͷ��ڴ�
void free_sapce(struct ConfigInfo* config_info);