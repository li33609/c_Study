#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

// %*s或%*d
void test01()
{
	char buf[128] = "123456abcdef";
	char str[128] = { 0 };

	sscanf(buf, "%*d%s", str);
	printf("%s\n", str);
}

// 默认数字为字符串，处理方法加空格,或加\t
void test02()
{
	char buf[128] = "abcdef\t123456";
	char str[128] = { 0 };

	sscanf(buf, "%*s%s", str);
	printf("%s\n", str);
}

// %[a - z],匹配a到z中任意字符(尽可能多的匹配)
void test03()
{
	char buf[128] = "abcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*[a-z]%s", str);
	printf("str=%s\n", str);
}

// %[aBc],匹配a、B、c中一员，贪婪性
// 先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
void test04()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*[aBc]%s", str);
	printf("str=%s\n", str);
}

// %[width]s, 读指定宽度的数据
void test05()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%*5s%s", str);
	printf("str=%s\n", str);
}

// %[^a], 匹配非a的任意字符，贪婪性
// %[^a-z], 表示读取除a-z以外的所有字符
void test06()
{
	char buf[128] = "aBcdef123456";
	char str[128] = { 0 };

	sscanf(buf, "%[^c]", str);
	printf("str=%s\n", str);
}

// 练习1
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