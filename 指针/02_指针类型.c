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

/*
// Ұָ�� û�ж���ָ���ָ��
int main01()
{
	// û�г�ʼ����ָ��(û��ֵ)
	// ָ��p����ĵ�ַһ���Ƕ�����ģ���ϵͳ�������
	int *p; // Ұָ��

	// ���
	// int a = 0;
	// p = &a;

	*p = 200;
	printf("%d\n",*p);

	system("pause");
	return 0;
}
*/

// ��ָ��
int main02()
{
	int a = 0;
	// ��ָ�룬��ָ���ֵ��Ϊ0��NULL��
	int *p = NULL; 

	// ʹ��ָ��ʱ����ָ�븳ΪNULL
	if (p != NULL)
	{
		p = &a;
	}

	*p = 200; // p�����0x0000�ĵ�ַ�������ַ�����ã�ϵͳ��ʼ��
	printf("%d\n", *p);

	system("pause");
	return 0;
}


// ����ָ��
int main03()
{
	// �����Զ���void���ͱ��������ǿ��Զ���void *���͵�ָ�룬��Ϊָ�붼��4���ֽ�
	int a = 10;
	void  *p = (void *)&a;  // ����ָ����Ա�������ĵ�ַ

	// printf("%d\n", *p); // error �ڴ��С��һ��
	printf("%d\n", *(int *)p); // (int *)��ʾת������Ϊint *

	system("pause");
	return 0;
}


// const���ε�ָ��
int main04()
{
	// const int a = 10; // const����ֵ���ڴ治���Ըı䣬��ַ���Ըı�
	int a = 10;
	int b = 20;
	
	// ����const���ε���*
	// const int *p = &a; // ����ͨ�� *p���޸�p��ָ�Ŀռ�����
	// *p = 100; // erro
	 
	// const���α���p�� p����ĵ�ַ�������޸�
	// int * const p = &a;
	// p = &b; // erro
	
	const int* const p = &a; // p �����ָ���ܸı䣬����ͨ��*p�޸���ָ�������

	printf("*p = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return 0;
}


// �༶ָ��
int main()
{
	int a = 10;
	int *p = &a;
	// *q  int *p  int *(*q)
	int **q = &p;

	// ���*��&�����������
	// **q == *(*q) == *p == *��&a�� == a   
	printf("%d\n", **q);
	
	system("pause");
	return 0;
}


