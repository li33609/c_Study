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
		perror("打开文件错误！\n");
	}

	while (fgets(buf, 1024, file) != NULL)
	{
		// printf("%s", buf);
		lines++;
	}

	// 将文件光标，置首，光标一直指向文件末尾
	fseek(file, 0, SEEK_SET);

	// SEEK_CUR 文件中
	// SEEK_END 文件末尾

	return lines;
}

void reaf_file_data(FILE* file, char** pArray, int lines)
{
	if (file  == NULL)
	{
		perror("文件读取错误！\n");
	}
	if (pArray == NULL)
	{
		perror("未定义数组!\n");
	}
	if (lines <= 0)
	{
		perror("长度为空！\n");
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
		// 将buf数组置空，每循环一次把原来的也算上了
		memset(buf, 0, 1024);
	}
}

void printf_array(char** p, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		printf("第%d行,数据为:%s\n", i+1, p[i]);
	}
}

void freeSpace(char** p, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		printf("%s被释放了\n", p[i]);
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
		perror("打开文件错误！\n");
	}
	int lines = get_file_lines(pfile);

	printf("文件的有效行数：%d\n", lines);

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