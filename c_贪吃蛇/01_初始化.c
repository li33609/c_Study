#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<sys/types.h>
#include<sys/stat.h>

#define HIGH 20
#define WIDTH 40

typedef struct body
{
	int x;
	int y;
}BODY;

typedef struct snake
{
	BODY list[WIDTH * HIGH];
	int size; // �ߵ�ǰ��С
	BODY food;
	COORD coord; // ����λ�ã�winϵͳ���ж��壩
	int dx;
	int dy;
	int score;
	BODY tail;// ��¼β��
}SNAKE;

// ��ʼ����ͼ
void ui_init()
{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

// ��ʼ��ʳ��(���)
void init_food(SNAKE * sanke)
{
	srand(time(NULL));
	sanke->food.x = rand() % WIDTH;
	sanke->food.y = rand() % HIGH;
}

void init_snake(SNAKE *snake)
{
	// ��ͷ����
	snake->list[0].x = WIDTH / 2;
	snake->list[0].y = HIGH / 2;
	// ��β����
	snake->list[1].x = WIDTH / 2 - 1;
	snake->list[1].y = HIGH / 2;
	// ���Ի��ߵĴ�С
	snake->size = 2;
	// ʳ�����
	init_food(snake);
	// ��ʼ�����ƶ��ķ���
	snake->dx = 1;
	snake->dy = 0;
	// ��ʼ������
	snake->score = 0;
}

void show_ui(SNAKE *snake)
{
	// ��ʾ��,ÿ����ʾ�߻�ʳ���Ҫ���ù���λ��
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		// ���ù���λ��
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		if (0 == i)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}
	// ��ʾʳ��
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
	// ��ԭ��β�͵�λ����ʾΪ�ո�
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
}

// �ƶ���
void move_sanke(SNAKE *snake)
{
	// ��¼β������
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	// ������β
	for (int i = snake->size - 1; i > 0 ; i--)
	{
		snake->list[i] = snake->list[i - 1];
	}
	// ������ͷ
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;

}

void control_snake(SNAKE* snake)
{
	char key = 0;

	while (_kbhit()) // �ж��Ƿ��°��������²�����0
	{
		key = _getch();
	}
	switch (key)
	{
	case 'a':
		snake->dx = -1;
		snake->dy = 0;
		break;
	case 'w':
		snake->dx = 0;
		snake->dy = -1;
		break;
	case 's':
		snake->dx = 0;
		snake->dy = 1;
		break;
	case 'd':
		snake->dx = 1;
		snake->dy = 0;
		break;
	}
}

void game_end(SNAKE * snake)
{
	snake->coord.X = 0;
	snake->coord.Y = HIGH + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("��Ϸ�������÷�Ϊ%d\n", snake->score);
	Sleep(3000);
	exit(0); // �˳�����
}

void snake_eat_self(SNAKE *snake)
{
	// �����ͷ������λ����ͬ�������
	for (int i = 1; i < snake->size; i++)
	{
		if (snake->list[0].x == snake->list[i].x && 
			snake->list[0].y == snake->list[i].y)
		{
			game_end(snake);
		}
	}
}

void snake_eat_food(SNAKE *snake)
{
	if (snake ->list[0].x == snake -> food.x && snake->list[0].y == snake->food.y)
	{
		init_food(snake);
		snake->size++;
		snake->score += 10;
	}
}

// ��ʼ��ǽ
void init_wall(SNAKE* snake)
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDTH; j++)
		{
			if (i == HIGH || j == WIDTH)
			{
				printf("+");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void start_game(SNAKE *snake)
{
	while (snake->list[0].x < WIDTH && snake->list[0].x >= 0 &&
		snake->list[0].y < HIGH && snake->list[0].y >= 0)
	{
		// init_wall(snake);
		control_snake(snake);// �������ƶ�
		move_sanke(snake); // �ƶ��ߵ�λ��
		// system("cls"); // ����
		show_ui(snake); // ��ʾ��
		snake_eat_self(snake);// �Ƿ������Լ�
		snake_eat_food(snake);// �Ե�ʳ��
		Sleep(300);
	}
	game_end(snake);
}

void hide_cur()
{
	//���ؿ���̨���
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


int main()
{
	// ui_init();
	SNAKE *snake =(SNAKE *)malloc(sizeof(SNAKE));

	hide_cur();// ���ع��
	init_wall(snake);
	init_snake(snake);
	show_ui(snake);
	start_game(snake);
	while (1);

	system("pause");
	return 0;
}