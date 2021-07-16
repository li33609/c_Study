#include "config.h"

int get_file_line(const char* file_path)
{
	FILE* file_read = fopen(file_path, "r");
	if (file_read == NULL)
	{
		perror("error!");
	}

	int line = 0;
	char buf[1024] = { 0 };

	while (fgets(buf, 1024, file_read) != NULL )
	{
		if (is_invalid_line(buf))
		{
			line++;
		}
	}

	fclose(file_read);
	return line;
}

int is_invalid_line(char* str)
{
	if (str[0] == '\n' || strchr(str, ':') == NULL)
	{
		return 0;
	}

	return 1;
}

void parse_file(const* file_path, int lines, struct ConfigInfo** config_info)
{
	struct ConfigInfo* config = malloc(sizeof(struct ConfigInfo) * lines);
	if (config == NULL)
	{
		return;
	}

	FILE* file = fopen(file_path, "r");
	if (file == NULL)
	{
		return;
	}

	char buf[1024] = { 0 };
	int index = 0;

	while (fgets(buf, 1024, file) != NULL)
	{
		if (is_invalid_line(buf))
		{
			// 将其中值清零
			memset(config[index].key, 0, 64);
			memset(config[index].value, 0, 64);

			// 截取：的值
			char* pos = strchr(buf, ':');

			// 截取key数据
			strncpy(config[index].key, buf, pos - buf);

			// 截取value数据
			strncpy(config[index].value, pos + 1, strlen(pos + 1) - 1); // -1的目的不要换行

			// printf("key = %s\n", config[index].key);
			// printf("value = %s\n", config[index].value);

			index++;
		}
		memset(buf, 0, 1024);
	}

	*config_info = config;
	fclose(file);
}

char* get_value_by_key(char* key, struct ConfigInfo* config, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		if (strcmp(config[i].key, key) == 0)
		{
			return config[i].value;
		}
	}
	
	return NULL;
}

void free_sapce(struct ConfigInfo* config_info)
{
	if (config_info == NULL)
	{
		return;
	}

	free(config_info);
	config_info = NULL;
}
