#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����ָ���������
//1 *����Ž�ϴ�����һ��ָ�����  
//2 Ҫ����˭�ĵ�ַ,�����Ķ�����ʽ���ڴ˴�
//3 ��*p�滻������ı���
//*p

//����
//1��*��ϴ������һ��ָ�����
//2p�Ǳ���,p�������ǽ�����p�����Ϻ�,ʣ�µ����;���ָ�����������  int   *
//3ָ�����p��������ʲô�������ݵĵ�ַ ,��ָ�����p��ָ�����p�����*һ���Ϻ�,
//ʣ��ʲô���;ͱ���ʲô�������ݵĵ�ַ
//p = &a;

// ָ�����ַ���
int main01()
{
	char ch[] = "helloworld";
	// ����һ��ָ�뱣��������Ԫ�ص�ַ
	char* p = ch;

	*p = 'm';
	printf("%s\n", p);
	printf("%s\n", p+3);
	printf("%c\n", *(p + 3));
	printf("%d\n", sizeof(ch)); // 11
	printf("%d\n", sizeof(p)); // 4
	printf("%d\n", strlen(ch)); // 
	printf("%d\n", strlen(p)); //

	system("pause");
	return 0;
}


int main02()
{
	char ch[] = "helloworld";
	char* p = ch;

	p = "abcdef"; // �ַ������������ֳ�����
	printf("%s\n", p);
	printf("%d\n", sizeof(p)); // 4
	printf("%d\n", sizeof("abcdef")); // 7

	system("pause");
	return 0;
}


char * my_strcat(char *ch1,char *ch2)
{
	int n = strlen(ch1);
	int i = 0;

	while (*(ch2 + i)!= 0)
	{
		*(ch1 + n + i) = *(ch2 + i);
		// ch1[n+i] = ch2[i];
		i++;
	}
	*(ch1 + n + i) = 0;

	return ch1;
}

int main03()
{
	char str1[128] = "hello";
	char str2[128] = "world";

	// my_strcat(str1, str2);

	printf("%s\n", my_strcat(str1, str2));

	system("pause");
	return 0;
}


// �ַ�ָ������
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	char* p3 = "hahaha";
	char* num[3] = {p1,p2,p3};
	char** p = num;

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", num[i]);
	}
	printf("%c\n", *(num[1]+1));
	printf("%c\n", *(num[2]+2));
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", *(p + i));
	}
	printf("%c\n", *(*(p + 1) + 1));

	system("pause");
	return 0;
}

