#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ×é°ü
int main01()
{
	int year = 2021;
	int mounth = 6;
	int day = 8;
	char buf[128] = "";
	FILE* fp = NULL;
	fp = fopen("./a.txt", "w");

	fprintf(fp, "%04d:%02d:%02d", year, mounth, day);
	// sprintf(buf, "%04d:%02d:%02d", year, mounth, day);
	// fputs(buf, fp);
	// printf("%s\n", buf);
	fclose(fp);

	system("pause");
	return 0;
}


// ²ð°ü
int main()
{
	int year = 2021;
	int mounth = 6;
	int day = 8;
	char buf[128] = "";
	FILE* fp = NULL;
	fp = fopen("./a.txt", "r");
	fscanf(fp, "%d:%d:%d", &year, &mounth, &day);
	
	printf("%d %d %d\n", year, mounth, day);
	fclose(fp);

	system("pause");
	return 0;
}