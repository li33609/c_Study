#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 动态数组结构体
struct dynamicArray
{
	// 真实在堆区开辟数组的指针
	void** pAddr;
	// 数组容量
	int n_Capacity;
	// 数组大小
	int n_Size;
};

// 初始化数组  初始化数组容量 返回值 数组指针
struct dynamicArray* init_dynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	// 给数组分配内存
	struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));

	if (arr == NULL)
	{
		return NULL;
	}
	// 给属性初始化
	arr->pAddr = malloc(sizeof(void *) * capacity);
	arr->n_Capacity = capacity;
	arr->n_Size = 0;

	return arr;
}

// 插入数组
void insert_dynamicArray(struct dynamicArray* arr, void* data, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->n_Size)
	{
		// 尾插
		pos = arr->n_Size;
	}

	// 判断数组是否满了
	if (arr->n_Size == arr->n_Capacity)
	{
		// 1.申请更大的空间
		int newCapacity = arr->n_Capacity * 2;

		// 2.开辟空间
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		// 3.将原空间数据拷贝到新空间下
		memcpy(newSpace, arr->pAddr, sizeof(void*) * arr->n_Capacity);

		// 4.释放空间
		free(arr->pAddr);

		// 5.更改指向
		arr->pAddr = newSpace;

		// 6.更新容量
		arr->n_Capacity = newCapacity;
	}

	// 将新元素插入
	for (int i = arr->n_Size - 1; i >= pos; --i)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// 插入数据
	arr->pAddr[pos] = data;

	// 更新数据
	arr->n_Size++;
}

// 遍历
void foreach_dynamicArray(struct dynamicArray* arr, void(*myPrint)(void*))
{
	if (arr == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->n_Size; ++i)
	{
		myPrint(arr->pAddr[i]);
	}
}

struct Person
{
	char name[64];
	int age;
};

// 回调函数，打印数据
void printPerson(void* data)
{
	struct Person* person = data;
	printf("姓名：%s, 年龄%d\n", person->name, person->age);
}

// 测试动态数组
void test01()
{
	// 初始化动态数组
	struct dynamicArray* arr = init_dynamicArray(5);

	struct Person p1 = { "赵云", 18 };
	struct Person p2 = { "关羽", 20 };
	struct Person p3 = { "张飞", 19 };
	struct Person p4 = { "刘备", 30 };
	struct Person p5 = { "黄忠", 50 };
	struct Person p6 = { "马超", 16 };

	printf("数组容量：%d\n", arr->n_Capacity);
	printf("数组大小：%d\n", arr->n_Size);

	// 插入数据
	insert_dynamicArray(arr, &p1, 0);
	insert_dynamicArray(arr, &p2, 0);
	insert_dynamicArray(arr, &p3, 1);
	insert_dynamicArray(arr, &p4, -1);
	insert_dynamicArray(arr, &p5, 1);
	insert_dynamicArray(arr, &p6, 0);

	// 
	foreach_dynamicArray(arr, printPerson);

	printf("数组容量：%d\n", arr->n_Capacity);
	printf("数组大小：%d\n", arr->n_Size);
}


int main()
{
	test01();

	return 0;
}