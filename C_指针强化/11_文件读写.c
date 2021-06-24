#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


int get_file_lines(FILE *file)
{
	int lines = 0;
	char buf[1024];

	if (file == NULL)
	{
		perror("���ļ�����\n");
	}

	while (fgets(buf, 1024, file) != NULL)
	{
		// printf("%s", buf);
		lines++;
	}

	// ���ļ���꣬���ף����һֱָ���ļ�ĩβ
	fseek(file, 0, SEEK_SET);

	// SEEK_CUR �ļ���
	// SEEK_END �ļ�ĩβ

	return lines;
}

void reaf_file_data(FILE* file, char** pArray, int lines)
{
	if (file  == NULL)
	{
		perror("�ļ���ȡ����\n");
	}
	if (pArray == NULL)
	{
		perror("δ��������!\n");
	}
	if (lines <= 0)
	{
		perror("����Ϊ�գ�\n");
	}

	char buf[1024] = {0};
	int index = 0;

	while (fgets(buf, 1024, file) != NULL)
	{
		int array_len = strlen(buf) + 1;
		buf[strlen(buf) - 1] = '\0';
		char* p = malloc(sizeof(char) * array_len);
		strcpy(p, buf);

		pArray[index++] = p;
		// ��buf�����ÿգ�ÿѭ��һ�ΰ�ԭ����Ҳ������
		memset(buf, 0, 1024);
	}
}

void printf_array(char** p, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		printf("��%d��,����Ϊ:%s\n", i+1, p[i]);
	}
}

void freeSpace(char** p, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		printf("%s���ͷ���\n", p[i]);
		free(p[i]);
		p[i] = NULL;
	}

	free(p);
	p = NULL;
}

void test01()
{
	FILE* pfile = fopen("./a.txt", "r");
	if (pfile == NULL)
	{
		perror("���ļ�����\n");
	}
	int lines = get_file_lines(pfile);

	printf("�ļ�����Ч������%d\n", lines);

	char ** p_file = malloc(sizeof(char *) * lines);

	reaf_file_data(pfile, p_file, lines);

	printf_array(p_file, lines);
	freeSpace(p_file, lines);
	p_file = NULL;

	fclose(pfile);
	pfile = NULL;
}


int main()
{
	test01();

	system("pause");
	return 0;
}