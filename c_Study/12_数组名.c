#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main01()
{
	int num[10];

	printf("%u\n", &num[0]);
	printf("%u\n", num);
	printf("%u\n", &num);

	printf("%u\n", &num[0]+1);
	printf("%u\n", num+1);
	printf("%u\n", &num+1);

	system("pause");
	return 0;
}


int main02()
{
	int num[7] = {2,5,10,6,-10,56,5};
	int max = num[0];

	for (int i = 1; i < sizeof(num)/sizeof(num[0]); i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
	}
	printf("%d\n",max);
	
	system("pause");
	return 0;
}


int main03()
{
	int num[10] = { 2,5,10,6,-10,56,5,98,15,22 };
	int tmp;
	int j = sizeof(num) / sizeof(num[0]) - 1;
	int i = 0;

	while (i<j)
	{
		tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
		i++;
		j--;
	}
	for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		printf("%d ", num[i]);
	}

	system("pause");
	return 0;
}


// 冒泡排序
int main04()
{
	int num[10] = { 2,5,10,6,-10,56,5,98,15,22 };
	int j = 0;
	int n = sizeof(num) / sizeof(num[0]);
	int i = 0;
	int tmp = 0;

	for ( i = 0; i < n - 1; i++)
	{
		for ( j = 0; j < n - 1 - i; j++)
		{
			if (num[j]>num[j+1])
			{
				tmp = num[j+1];
				num[j+1] = num[j];
				num[j] = tmp;
			}
		}
	}
	for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		printf("%d ", num[i]);
	}
	
	system("pause");
	return 0;
}


int main05()
{
	int a[2][4] = { {1,2,3,4},{5,6,7,8} };
	// 二维数组定义时不能省略列坐标
	int b[][2] = { 1,2,3,48, 5,6,7,88 };
	int n = sizeof(a) / sizeof(a[0][0]);// 元素个数
	int line = sizeof(a) / sizeof(a[0]);// 行数
	int clu = sizeof(a[0]) / sizeof(a[0][0]);// 列数
	
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < clu; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}


// 练习题
int main06()
{
	float a[5][3] = { {80, 75, 56},{59, 65, 71},{59, 63, 70},{85, 45, 90},{76, 77, 45} };
	int line = sizeof(a) / sizeof(a[0]);
	int clu = sizeof(a[0]) / sizeof(a[0][0]);
	float aver[3] = { 0 };
	float sum = 0.0;
	int num[3] = { 0 };
	
	for (int i = 0; i < clu; i++)
	{
		sum = 0.0;
		for (int j = 0; j < line; j++)
		{
			sum += a[j][i];
			if (a[j][i]<60)
			{
				num[i]++;
			}
		}
		aver[i] = sum / 5;
	}
	for (int i = 0; i < clu; i++)
	{
		printf("aver = %f\n", aver[i]);
	}
	for (int i = 0; i < clu; i++)
	{
		printf("num = %d\n", num[i]);
	}

	system("pause");
	return 0;
}


// 多维数组
int main()
{
	

	system("pause");
	return 0;
}