#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

	// ֻ�� r �����ڣ�������
	// ֻд����ļ� w �����ڣ������ļ�
	// �ɶ���д r+
	// �ɶ���д����ļ� w+
	// ׷�� a �����ڣ������ļ�
	// b �������ļ�
	FILE *fp = fopen("./a.txt", "r"); // �򿪵�ǰ�ļ����ɹ����ؽṹ�壬ʧ�ܷ���NULL

	if (NULL == fp)
	{
		perror("open:");
		return;
	}
	fclose(fp); // �ر��ļ�

	system("pause");
	return 0;
}