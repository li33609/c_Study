#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 调换字母大小
int main01()
{
	char buf[64] = "";

	printf("请输入小于64的字符串：\n");
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


// 猜数字
int main()
{
	int rand_num[4];
	int guss_num[4];
	int num;
	int i = 0;
	int n = 0;

	printf("猜数字：系统随机生成四位数数字。\n");
	srand(time(NULL));
	for ( i = 0; i < 4; i++)
	{
		rand_num[i] = rand() % 10;
	}
	while (1)
	{
		printf("请输入一个四位数：\n");
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
				printf("第%d位输入的数大。\n", i + 1);
			}
			else if(guss_num[i] < rand_num[i])
			{
				printf("第%d位输入的数小。\n", i + 1);
			}
			else if(guss_num[i] == rand_num[i])
			{
				printf("第%d输入的正确。\n", i + 1);
				n++;
			}
		}
		if (n == 4)
		{
			printf("猜对了，游戏结束。\n");
			break;
		}
	}

	system("pause");
	return 0;
}

