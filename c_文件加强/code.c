#include "code.h"


// º”√‹
void code_file(char* source_file, char* dest_file) 
{
	FILE* fp1 = fopen(source_file, "r");
	FILE* fp2 = fopen(dest_file, "w");

	if ( !fp1 || !fp2)
	{
		return;
	}

	char ch;
	short temp;

	while ( (ch = fgetc(fp1)) != EOF )
	{
		// #(35) short
		// 0000 0000 0010 0011 << 4
		// 0000 0010 0011 0000
		// 1000 0000 0000 0000 |
		// 1000 0010 0011 0000 + 0000 ~ 1111  0 ~ 15
		// 1000 0010 0011 0101

		temp = (short)ch;
		temp = temp << 4;
		temp = temp | 0x8000;
		temp = temp + rand() % 16;

		fprintf(fp2, "%hd", temp);
	}

	fclose(fp1);
	fclose(fp2);
}

// Ω‚√‹
void dest_code_file(char* source_file, char* dest_file)
{
	FILE* fp1 = fopen(source_file, "r");
	FILE* fp2 = fopen(dest_file, "w");

	if (!fp1 || !fp2)
	{
		return;
	}

	char ch;
	short temp;

	while ( !feof(fp1) )
	{
		// 1000 0010 0011 0101 << 1
		// 0000 0100 0110 1010 >> 5
		// 0000 0000 0010 0011
		// 0000 0000 0010 0011
		fscanf(fp1, "%hd", &temp);

		temp = temp << 1;
		temp = temp >> 5;

		char ch = (char)temp;
		fputc(ch, fp2);
	}

	fclose(fp1);
	fclose(fp2);
}