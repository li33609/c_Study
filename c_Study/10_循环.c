#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main01()
{
	int i = 0;
	int sum = 0;

	/* while(i <= 100)
	{
		sum += i;
		i++;
	}
	printf("sum = %d\n", sum); */

	// do �����������ж�
	do
	{
		sum += i;
		i++;
	} while (i <= 100);
	printf("sum = %d\n", sum);

	system("pause");
	return 0;
}


int main02()
{
	int i = 0;
	int sum = 0;
	
	for (i = 0; i <= 100; i++)
	{
		sum += i;
	}
	printf("sum = %d\n", sum);

	system("pause");
	return 0;
}


int main03()
{
	int i = 0;
	int j = 0;
	int sum = 0;

	for (i = 0; i <= 10; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("i = %d j = %d\n", i, j);
		}
	}

	system("pause");
	return 0;
}


int main04()
{
	int i = 0;
	int j = 0;
	int sum = 0;

	for (i = 0; i <= 5; i++)
	{
		if (i == 2)
		{
			// ����ѭ��
			// break;
			// ��������ѭ��
			continue;
		}
		printf("i = %d \n", i);
	}

	system("pause");
	return 0;
}

int main05()
{
	int i = 0;
	int j = 0;
	int sum = 0;

	printf("100���ڵ�����7����:\n");
	for (i = 0; i <= 100; i++)
	{
		if (i % 7 == 0)
		{
			printf("i = %d \n", i);
		}
	}

	system("pause");
	return 0;
}

int main()
{
	int i = 0;
	int m = 0;
	int n = 0;
	int sum = 0;

	printf("����2������:\n");
	scanf("%d %d", &m, &n);
	for ( i = m; i <= n; i++)
	{
		if ((i%7!=0)&&(i%5!=0))
		{
			sum += i;
		}
	}
	printf("sum = %d\n", sum);
	

	system("pause");
	return 0;
}