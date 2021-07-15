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