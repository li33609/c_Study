#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>


typedef struct stu
{
	int id;
	char name[128];
}STU;


// 写入数据
int main01()
{
	int count = 0;
	STU num[3] = { {1, "lisi"}, {2, "wangwu"}, {3, "zhangsan"} };

	FILE* fp = NULL;
	fp = fopen("./a.txt", "w");
	if (!fp)
	{
		perror("open:");
	}
	// 读数据 fread()
	count = fwrite(num, 1, sizeof(num), fp);
	printf("count = %d\n", count);
	fclose(fp);

	system("pause");
	return 0;
}


// fseek 设置光标
int main02()
{

	FILE* fp = NULL;
	fp = fopen("./a.txt", "w");
	if (!fp)
	{
		perror("open:");
	}

	fseek(fp, 0, SEEK_SET); // 移动到光标头
	fputs("seek", fp);

	fclose(fp);
	system("pause");
	return 0;
}

// remove(),删除文件
// rename()，改名
// stat 查看文件类型和状态
int main()
{
	struct stat buf;
	int ret = 0;

	ret = stat("./a1.txt", &buf);
	if (ret == -1)
	{
		printf("file not found!");
	}
	printf("%d\n", buf.st_size);
	
	system("pause");
	return 0;
}