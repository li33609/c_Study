#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include <time.h>
#include "config.h"
#include "code.h"


int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));

	int lines = get_file_line("./config.txt");
	printf("文件的有效行数为：%d\n", lines);

	struct ConfigInfo* config_info = NULL;
	parse_file("./config.txt", lines, &config_info);

	// 根据key获取value
	printf("hero_id=%s\n", get_value_by_key("heroId", config_info, lines));
	printf("hero_name=%s\n", get_value_by_key("heroName", config_info, lines));
	printf("hero_apk=%s\n", get_value_by_key("heroAtk", config_info, lines));
	printf("hero_def=%s\n", get_value_by_key("heroDef", config_info, lines));
	printf("hero_info=%s\n", get_value_by_key("heroInfo", config_info, lines));

	// 加密文件
	code_file("./config.txt", "加密后文件.txt");

	// 解密文件
	dest_code_file("加密后文件.txt", "解密文件.txt");

	free_sapce(config_info);

	system("pause");
	return EXIT_SUCCESS;
}