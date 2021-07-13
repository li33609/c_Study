#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct person
{
	char* name;
	char** students;
}Teacher;

void allocate_space(Teacher*** teacher_pArray)
{
	if (teacher_pArray == NULL)
	{
		return;
	}

	Teacher** ts = malloc(sizeof(Teacher *) * 3);
	
	for (int i = 0; i < 3; i++)
	{
		ts[i] = malloc(sizeof(Teacher));
		ts[i]->name = malloc(sizeof(char) * 64);
		sprintf(ts[i]->name, "teacher_%d", i + 1);
		ts[i]->students = malloc(sizeof(char *) * 4);
		for (int j = 0; j < 4; j++)
		{
			ts[i]->students[j] = malloc(sizeof(char) * 64);
			sprintf(ts[i]->students[j], "%s_students_%d", ts[i]->name, j + 1);
		}
	}

	*teacher_pArray = ts;
}

void printf_array(Teacher** teacher_pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", teacher_pArray[i]->name);
		for (int j = 0; j < 4; j++)
		{
			printf("   %s\n", teacher_pArray[i]->students[j]);
		}
	}
}

void free_array(Teacher** teacher_pArray, int len)
{
	if (teacher_pArray == NULL)
	{
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (teacher_pArray[i]->name != NULL)
		{
			free(teacher_pArray[i]->name);
			teacher_pArray[i]->name == NULL;
		}
		for (int j = 0; j < 4; j++)
		{
			if (teacher_pArray[i] -> students[j] != NULL)
			{
				free(teacher_pArray[i]->students[j]);
				teacher_pArray[i]->students[j] == NULL;
			}
		}
		free(teacher_pArray[i]->students);
		teacher_pArray[i]->students = NULL;

		free(teacher_pArray[i]);
		teacher_pArray[i] = NULL;
	}
	free(teacher_pArray);
	teacher_pArray = NULL;
}


void test01()
{
	Teacher** teacher_pArray = NULL;

	allocate_space(&teacher_pArray);

	printf_array(teacher_pArray, 3);

	free_array(teacher_pArray, 3);
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}