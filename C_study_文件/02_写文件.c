#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char b[] = "hello";

	FILE* fp = fopen("./a.txt", "a+");
	if (NULL == fp)
	{
		perror("open:");
		return;
	}

	/*
	// д���ļ�
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		fputc(b[i], fp);
	}
	*/

	// char c = fgetc(fp);
	// printf("%c\n", c);

	char buf[128] = "";
	int i = 0;
	// ���������ļ�����-1ʱ��ֱ���жϣ�ʹ��feof�������,feof�������Ϊ��0��0��ʾ��û����
	// while ((buf[i++] = fgetc(fp)) != -1)
	do
	{
		buf[i++] = fgetc(fp);
	} while (!feof(fp));

	printf("%s\n", buf);

	// fclose(fp); // �ر��ļ�

	system("pause");
	return 0;
}
