#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAX 6

// �����������ĸ
void start(char *str)
{
	srand((unsigned int)time(NULL));
	int i = 0;

	for ( i = 0; i < MAX - 1; i++)
	{
		str[i] = rand() % 26 + 'a';
	}

	*(str + MAX - 1) = '\0';

}

void on_game(char *str)
{
	char ch;
	int i = 0;
	int count = 0;
	time_t t_start, t_end;

	system("cls");
	printf("%s\n", str);

	count = 0;
	for ( i = 0; i < MAX  - 1; i++)	
	{
		ch = _getch();
		if (i == 0)
		{
			t_start = time(NULL);
		}
		if(ch == *(str + i))
		{
			printf("%c", ch);
			count++;
		}
		else
		{
			printf("�������");
		}
	}
	t_end = time(NULL);

	printf("��Ϸʱ�䣺%1d s\n ", t_end - t_start);
	printf("��ȷ����:%d\n", count);
	printf("��ȷ����:%1f %% \n", (count * 1.0 / (MAX -1)) * 100);
	printf("����ESC�˳���\n");
}


int main()
{
	char str[MAX] = { 0 };

	while (1)
	{
		start(str);
		on_game(str);

		char ch = _getch();

		if (ch == 27)
		{
			break;
		}

		system("cls");
	}
	

	system("pause");
	return 0;
}
