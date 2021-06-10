#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>
#include<sys/types.h>
#include<sys/stat.h>

#define LINE 111102
#define FILENAME "./dict.txt"

FILE *my_OpenFile()
{
	FILE* fp = fopen(FILENAME, "r");
	if (NULL == fp)
	{
		perror("open:");
	}

	return fp;
}

typedef struct dict
{
	char* key;
	char* content;
}DICT;

void filter_dict(char *buf)
{
	int n = strlen(buf) - 1;
	while (buf[n] == ' ' || buf[n] == '\n' || buf[n] == '\r' || buf[n] == '\t')
	{
		n--;
	}
	buf[n + 1] = 0;
}

void dict_init(DICT **tmp, int n)
{
	char* q = NULL;
	int i = 0;
	char buf[256] = "";
	DICT* p;
	p = malloc(sizeof(DICT) * n );
	FILE* fp = my_OpenFile();

	while (1)
	{
		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		filter_dict(buf);
		p[i].key = malloc(strlen(buf)+1);
		strcpy(p[i].key, buf + 1);

		q = fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		p[i].content = malloc(strlen(buf) + 1);
		strcpy(p[i].content, buf + 6);

		i++;
	}
	fclose(fp);

	*tmp = p;
}

int select_world(char* cmd, DICT* p, char* content, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(cmd, p[i].key) == 0)
		{
			strcpy(content, p[i].content);
			return 1;
		}
	}
	return 0;
}

int statistics_num()
{
	int i = 0;
	char buf[256] = "";
	FILE* fp = my_OpenFile();
	char* q = NULL;

	while (1)
	{
		q = fgets(buf, sizeof(buf), fp);
		if (NULL == q)
		{
			break;
		}
		q = fgets(buf, sizeof(buf), fp);
		if (NULL == q)
		{
			break;
		}
		i++;
	}
	fclose(fp);
	return i;
}


int main()
{
	char cmd[256] = "";
	char content[256] = "";
	int ret = 0;
	int n = 0;
	DICT* dict = NULL;
	clock_t start, end;
	
	n = statistics_num();
	printf("该词典有%d个单词。\n");
	dict_init(&dict, n);

	while (1)
	{
		printf("请输入单词：");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd) - 1] = 0;
		start = clock();
		ret = select_world(cmd, dict, content, n);
		if (ret == 0)
		{
			printf("无此单词！\n");
		}
		else
		{
			printf("此单词的翻译：%s", content);
		}
		end = clock();
		printf("查寻时间%dms。\n", end-start);
	}

	system("pause");
	return 0;
}
