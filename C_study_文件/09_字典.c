#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>


typedef struct world
{
	char key[256];
	char content[256];
}DICT;

void dict_init(DICT **tmp)
{
	DICT* p ;
	p = malloc(sizeof(DICT) * 2);
	
	strcpy(p[0].key, "hello");
	strcpy(p[0].content, "你好");
	strcpy(p[1].key, "world");
	strcpy(p[1].content, "世界");
	*tmp = p;
}

int select_world(char *cmd, DICT *p, char *content, int n)
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
	

int main()
{
	int ret = 0;
	int i = 0;
	char cmd[256] = "";
	char content[256] = "";
	DICT* dict = NULL;

	dict_init(&dict);
	while (1)
	{
		printf("请输入单词：");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd) - 1] = 0;
		// printf("%s\n", cmd);
		ret = select_world(cmd, dict, content, 2);
		if (ret == 0)
		{
			printf("无此单词！");
		}
		else
		{
			printf("此单词的翻译：%s\n", content);
		}
	}

	system("pause");
	return 0;
}
