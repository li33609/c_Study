#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
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


int main01()
{
	char str1[128] = "world";
	char str2[128] = "hello";

	// �ַ�������
	// strcpy(str1, str2);
	// ����2���ַ�
	// strncpy(str1, str2, 2);
	// printf("%s\n", str1);
	
	// ����
	strcat(str2, str1);
	printf("%s\n", str2);
	strncat(str2, str1, 2);
	printf("%s\n", str2);
	
	// ����Ƚϴ�С(str1 > str2 == 1, str1 = str2 == 0, str1 < str2 == -1)
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str2, 1));

	system("pause");
	return 0;
}


// �������
int main02()
{
	int year = 2021;
	int month = 5;
	int day = 28;
	char buf[128] = "hello";

	// ����ӡ����浽buf������
	int len = sprintf(buf, "year=%d month=%d day=%d \n", year, month, day); // ������ϰ�����
	printf("buf=[%s]", buf);
	printf("len=%d\n", len);

	system("pause");
	return 0;
}


// �������
int main03()
{
	int year = 0;
	int month = 0;
	int day = 0;
	char buf[1024] = "2021:05:20";

	sscanf(buf, "%d:%d:%d", &year, &month, &day); // ��buf�л�ȡ����
	printf("%d %d %d\n", year, month, day);

	system("pause");
	return 0;
}


char* my_strchar(char *q, char ch)
{
	int i = 0;

	while (q[i] != 0)
	{
		if (q[i] == ch)
			return &q[i];
		i++;
	}
	if (q[i] == 0)
	{
		return NULL;
	}
}


// �������в����ַ�����λ�ã��ɹ��򷵻ظ�ֵ�ĵ�ַ��ʧ�ܷ���NULL
int main04()
{
	char str[] = "sadasddwdsfdcdsf";
	// char* p = strchr(str, 'a');
	char* p = my_strchar(str, 'a');

	printf("%s\n", p);

	system("pause");
	return 0;
}


// �������в����ַ�������λ�ã��ɹ��򷵻ظ�ֵ�ĵ�ַ��ʧ�ܷ���NULL
int main05()
{
	char str1[] = "sadasddwdsfdcdsf";
	char str2[] =  "ad";
	char* p = strstr(str1, str2);

	printf("%s\n", p);

	system("pause");
	return 0;
}


int main06()
{
	char  str1[] = "1222254565#guoguo#123456";
	char* p[10] = { NULL };// ��ʼ������Ԫ��ȫΪNULL
	int i = 0;
	/*
	char* p1 = strtok(str1, "#"); // ��str1��#�и����ǰ����ַ���
	printf("%s\n", p1);

	char* p2 = strtok(NULL, "#"); // ��str1��#�и����ǰ����ַ���
	printf("%s\n", p2);

	char* p3 = strtok(NULL, "#"); // ��str1��#�и����ǰ����ַ���
	printf("%s\n", p3);
	*/
	do
	{
		if ( i == 0 )
		{
			p[i] = strtok(str1, "#");
		}
		else
		{
			p[i] = strtok(NULL, "#");
		}
	} while (p[i++] != NULL);  // p[i] != NULL i=i+1 ���strtok==NULL�и����

	i = 0;
	while (p[i] != 0)
	{
		printf("%s\n", p[i++]);
	}

	system("pause");
	return 0;
}


// atoi ���ַ�ת������
int main07()
{
	// 0-9���ַ���+-�ţ�������ǽ���
	char num1[] = "1234";
	char num2[] = "121.34";
	int sum1 = atoi(num1);
	float sum2 = atof(num2);

	printf("%d\n", sum1);
	printf("%f\n", sum2);

	system("pause");
	return 0;
}


int str_num(char* str, char* dst)
{
	int n = 0;
	char* p = str;

	do
	{
		p = strstr(p, dst);
		if (p != NULL)
		{
			n++;
			p = p + strlen(dst);
		}

	} while (p != NULL);

	return n;
}

// �����ַ������ִ���
int main08()
{
	char str[] = "asdabababcijolnojlknolabc";
	char dst[] = "ab";
	int n = str_num(str, dst);

	printf("%d\n", n);

	system("pause");
	return 0;
}


// 
int main09()
{
	char src[] = "        hello world         ";
	char str[128] = "";

	char* start = src;
	char* end =  &src[strlen(src) - 1];

	while (*start == ' ' && *start != 0)
	{
		start++;
	}
	while (*end == ' ' && end == start)
	{
		end--;
	}
	strcpy(str, start, end-start+1);
	printf("src = %s\n", src);
	printf("str = %s\n", str);

	system("pause");
	return 0;
}


// ����˳��
int main()
{
	char src[] = "helloworld";

	char* start = src;
	char* end = &src[strlen(src) - 1];

	while (start < end)
	{
		char ch = *end;
		*end = *start;
		*start = ch;
		end--;
		start++;
	}
	printf("%s\n", src);

	system("pause");
	return 0;
}