#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ������ĸ��С
int main01()
{
	char buf[64] = "";

	printf("������С��64���ַ�����\n");
	fgets(buf, sizeof(buf), stdin);
	int len = strlen(buf);
	for (int i = 0; i < len; i++)
	{
		if (buf[i]>='a' && buf[i]<='z')
		{
			buf[i] -= 32;
		}
		else if (buf[i] >= 'A' && buf[i] <= 'Z')
		{
			buf[i] += 32;
		}
		printf("%c", buf[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


// ������
int main()
{
	int rand_num[4];
	int guss_num[4];
	int num;
	int i = 0;
	int n = 0;

	printf("�����֣�ϵͳ���������λ�����֡�\n");
	srand(time(NULL));
	for ( i = 0; i < 4; i++)
	{
		rand_num[i] = rand() % 10;
	}
	while (1)
	{
		printf("������һ����λ����\n");
		scanf("%d", &num); 

		guss_num[3] = num % 10;
		guss_num[2] = (num / 10) % 10;
		guss_num[1] = (num / 100) % 10;
		guss_num[0] = (num / 1000) % 10;

		n = 0;
		for (i = 0; i < 4; i++)
		{
			if (guss_num[i] > rand_num[i])
			{
				printf("��%dλ���������\n", i + 1);
			}
			else if(guss_num[i] < rand_num[i])
			{
				printf("��%dλ�������С��\n", i + 1);
			}
			else if(guss_num[i] == rand_num[i])
			{
				printf("��%d�������ȷ��\n", i + 1);
				n++;
			}
		}
		if (n == 4)
		{
			printf("�¶��ˣ���Ϸ������\n");
			break;
		}
	}

	system("pause");
	return 0;
}

