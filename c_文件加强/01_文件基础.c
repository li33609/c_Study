#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct person
{
	char name[64];
	int age;
}Hero;


void test01()
{
	char buf[] = "python number 1";

	FILE* f_write = fopen("./a.txt", "w");
	if (f_write == NULL)
	{
		ferror("open file!");
	}

	for (int i = 0; i < sizeof(buf); i++)
	{
		fputc(buf[i], f_write);
	}
	fclose(f_write);

	char ch;

	FILE* f_read = fopen("./a.txt", "r");
	if (f_read == NULL)
	{
		ferror("open file!");
	}
	while ((ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}
	printf("\n");

	fclose(f_read);
}

// 格式化处理文件
void test02()
{
	FILE* f_write = fopen("./a.txt", "w");
	if (f_write == NULL)
	{
		ferror("error");
	}

	fprintf(f_write, "hello world %d", 111);
	fclose(f_write);


	// 格式化读取
	char buf[1024] = {0};

	FILE* f_read = fopen("./a.txt", "r");
	if (f_read == NULL)
	{
		ferror("error");
	}
	while ( !feof(f_read) )
	{
		fscanf(f_read, "%s", buf);
		printf("%s", buf);
	}

	fclose(f_read);
}

void test03()
{
	Hero heroes[4] = {
		{ "孙悟空", 999 },
		{ "亚瑟", 20 },
		{ "曹操", 80 },
		{ "鲁班", 5 },
	};

	FILE* f_write = fopen("./a.txt", "wb");
	if (f_write == NULL)
	{
		perror("error!");
	}

	for (int i = 0; i < 4; i++)
	{
		fwrite(&heroes[i], sizeof(Hero), 1 ,f_write);
	}

	fclose(f_write);


	//读文件
	FILE* f_read = fopen("./a.txt", "rb");

	if (f_read == NULL)
	{
		return;
	}

	Hero temp;
	// fread(&temp, sizeof(Hero), 4, f_read);
	/*for (int i = 0; i < 4; i++)
	{
		printf("姓名： %s  年龄：%d\n", temp[i].name, temp[i].age);
	}*/
	fseek(f_read, sizeof(Hero) * 2, SEEK_SET);

	fread(&temp, sizeof(Hero), 1, f_read);
	printf("姓名： %s  年龄：%d\n", temp.name, temp.age);

	fclose(f_read);
}


int main()
{
	test03();

	system("pause");
	return EXIT_SUCCESS;
}