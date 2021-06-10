#define _CRT_SECURE_NO_WARNINGS��
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


// д������
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
	// ������ fread()
	count = fwrite(num, 1, sizeof(num), fp);
	printf("count = %d\n", count);
	fclose(fp);

	system("pause");
	return 0;
}


// fseek ���ù��
int main02()
{

	FILE* fp = NULL;
	fp = fopen("./a.txt", "w");
	if (!fp)
	{
		perror("open:");
	}

	fseek(fp, 0, SEEK_SET); // �ƶ������ͷ
	fputs("seek", fp);

	fclose(fp);
	system("pause");
	return 0;
}

// remove(),ɾ���ļ�
// rename()������
// stat �鿴�ļ����ͺ�״̬
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