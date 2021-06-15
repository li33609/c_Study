#define _CRT_SECURE_NO_WARNINGS；
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
	int size; // 蛇当前大小
	BODY food;
	COORD coord; // 光标的位置（win系统已有定义）
	int dx;
	int dy;
	int score;
	BODY tail;// 记录尾巴
}SNAKE;

// 初始化地图
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

// 初始化食物(随机)
void init_food(SNAKE * sanke)
{
	srand(time(NULL));
	sanke->food.x = rand() % WIDTH;
	sanke->food.y = rand() % HIGH;
}

void init_snake(SNAKE *snake)
{
	// 蛇头坐标
	snake->list[0].x = WIDTH / 2;
	snake->list[0].y = HIGH / 2;
	// 蛇尾坐标
	snake->list[1].x = WIDTH / 2 - 1;
	snake->list[1].y = HIGH / 2;
	// 初试化蛇的大小
	snake->size = 2;
	// 食物随机
	init_food(snake);
	// 初始化蛇移动的方向
	snake->dx = 1;
	snake->dy = 0;
	// 初始化分数
	snake->score = 0;
}

void show_ui(SNAKE *snake)
{
	// 显示蛇,每次显示蛇或食物，都要设置光标的位置
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		// 设置光标的位置
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
	// 显示食物
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
	// 将原来尾巴的位置显示为空格
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
}

// 移动蛇
void move_sanke(SNAKE *snake)
{
	// 记录尾巴坐标
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	// 更新蛇尾
	for (int i = snake->size - 1; i > 0 ; i--)
	{
		snake->list[i] = snake->list[i - 1];
	}
	// 更新蛇头
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;

}

void control_snake(SNAKE* snake)
{
	char key = 0;

	while (_kbhit()) // 判断是否按下按键，按下不等于0
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
	printf("游戏结束，得分为%d\n", snake->score);
	Sleep(3000);
	exit(0); // 退出进程
}

void snake_eat_self(SNAKE *snake)
{
	// 如果蛇头和身体位置相同，则结束
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

// 初始化墙
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
		control_snake(snake);// 控制蛇移动
		move_sanke(snake); // 移动蛇的位置
		// system("cls"); // 清屏
		show_ui(snake); // 显示蛇
		snake_eat_self(snake);// 是否碰到自己
		snake_eat_food(snake);// 吃到食物
		Sleep(300);
	}
	game_end(snake);
}

void hide_cur()
{
	//隐藏控制台光标
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


int main()
{
	// ui_init();
	SNAKE *snake =(SNAKE *)malloc(sizeof(SNAKE));

	hide_cur();// 隐藏光标
	init_wall(snake);
	init_snake(snake);
	show_ui(snake);
	start_game(snake);
	while (1);

	system("pause");
	return 0;
}