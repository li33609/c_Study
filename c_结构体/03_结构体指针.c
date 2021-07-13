#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct person
{
	char* name;
	int age;
}STUDENT;

STUDENT** allocate_space()
{
	STUDENT** temp = malloc(sizeof(STUDENT *) * 3);

	for (int i = 0; i < 3; i++)
	{
		temp[i] = malloc(sizeof(STUDENT));
		temp[i]->name = malloc(sizeof(char) * 64);

		sprintf(temp[i]->name, "name_%d", i + 1);
		temp[i]->age = i + 1;
	}

	return temp;
}

void print_array(STUDENT** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s %d\n", pArray[i]->name, pArray[i]->age);
	}
}

void free_array(STUDENT** pArray, int len)
{
	if (pArray == NULL)
	{
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (pArray[i]->name != NULL)
		{
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}
		if (pArray != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}

	free(pArray);
	pArray = NULL;
}

void test01()
{
	STUDENT **pArray = NULL;

	pArray = allocate_space();
	print_array(pArray, 3);
	free_array(pArray, 3);
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}