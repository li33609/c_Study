#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

// %*s��%*d
void test01()
{
	char buf[128] = "123456abcdef";
	char str[128] = { 0 };

	sscanf(buf, "%*d%s", str);
	printf("%s\n", str);
}

// Ĭ������Ϊ�ַ������������ӿո�,���\t
void test02()
{
	char buf[128] = "abcdef\t123456";
	char str[128] = { 0 };

	sscanf(buf, "%*s%s", str);
	printf("%s\n", str);
}

// %[a - z],ƥ��a��z�������ַ�(�����ܶ��ƥ��)
void test03()
{
	char buf[128] = "abcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*[a-z]%s", str);
	printf("str=%s\n", str);
}

// %[aBc],ƥ��a��B��c��һԱ��̰����
// ��ƥ���һ���ַ��Ƿ���aBc�е�һ��������ǣ���ƥ�䣬���������ֹͣƥ��
void test04()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*[aBc]%s", str);
	printf("str=%s\n", str);
}

// %[width]s, ��ָ����ȵ�����
void test05()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*5s%s", str);
	printf("str=%s\n", str);
}

// %[^a], ƥ���a�������ַ���̰����
// %[^a-z], ��ʾ��ȡ��a-z����������ַ�
void test06()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%[^c]", str);
	printf("str=%s\n", str);
}

// ��ϰ1
void test07()
{
	char* ip = "127.8.8.8";
	int a, b, c, d ;

	sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
}

void test08()
{
	char* str = "abcde#lishijie@123456adf";
	char buf[1024] = { 0 };

	sscanf(str, "%*[^#]#%[^@]", buf);

	printf("buf=%s\n", buf);
}

void test09()
{
	char* str = "123abcd$myname@000qwe";
	char buf[1024] = { 0 };

	sscanf(str, "%*[^$]$%[^@]", buf);

	printf("buf=%s\n", buf);
}

void test10()
{
	char* str = "helloworld@itcast.cn";
	char buf01[64] = { 0 };
	char buf02[64] = { 0 };

	sscanf(str, "%[a-z]%*[@]%s", buf01, buf02);

	printf("buf01=%s\n", buf01);
	printf("buf02=%s\n", buf02);
}


int main()
{
	// test01();
	// test02();
	// test03();
	// test04();
	// test05();
	// test06();
	// test07();
	// test08();
	// test09();
	test10();
	

	system("pause");
	return 0;
}