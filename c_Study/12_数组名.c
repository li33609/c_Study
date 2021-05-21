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


// ð������
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
	// ��ά���鶨��ʱ����ʡ��������
	int b[][2] = { 1,2,3,48, 5,6,7,88 };
	int n = sizeof(a) / sizeof(a[0][0]);// Ԫ�ظ���
	int line = sizeof(a) / sizeof(a[0]);// ����
	int clu = sizeof(a[0]) / sizeof(a[0][0]);// ����
	
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


// ��ϰ��
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


// �ַ�����
int main07()
{
	// �ַ�����
	// ��\0�����������������
	// char a[5] = {'a', 'b', 'c', 'd', '\0'};
	char a[123] = "abcd\0def\0";
	int line = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < line; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");
	printf("%s\n", a);
	printf("%d\n", a);

	system("pause");
	return 0;
}


// ��ȡ�ַ�����
int main08()
{
	char num[128] = "";
	int i = 0;
	
	// scanf�����ո����
	// scanf("%s", num);
	
	// gets_s �����س��������ո񲻽�����������ɳ�����Ⱦ
	// gets_s(num, 128); // ()��Ĳ����Ƕ�ȡ�ַ����ĵ�ַ
	
	// fgets��ѻس�������
	fgets(num, sizeof(num), stdin); // �ܹ��Զ�����,stdinΪ��������

	// fgetsȥ���س�
	/* while (num[i] != '\0') // ����Ч�ַ��ĸ���
	{
		i++;
	}
	num[i - 1] = '\0'; */

	i = strlen(num); // ���ַ�������
	num[i - 1] = '\0';

	printf("num = %s\n", num);

	system("pause");
	return 0;
}


// �ַ��������
int main09()
{
	char buf[1024] = "hello world";
	// printf("buf = %s \n", buf);
	// puts(buf); // �Զ��ӻ���b
	fputs(buf, stdout);

	system("pause");
	return 0;
}


// �ַ���׷��
int main()
{
	char str_1[128] = "hello world";
	char str_2[128] = "hello world";
	int i, j = 0;

	i = strlen(str_1);
	while (str_2[j] != 0)
	{
		str_1[i] = str_2[j];
		i++;
		j++;
	}
	printf("str_1 = %s\n",str_1);

	system("pause");
	return 0;
}