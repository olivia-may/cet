// reads an esperanto-fied c file, printfs it out as a normal c file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "replacement_words.h"

static char * input_stream = NULL;
static char * output_stream = NULL;
static int i = 0;
static int output_offset = 0;

char * copy_file_to_memory(char * dir)
{
	FILE * file = fopen(dir, "r");
	char * file_contents = NULL;
	// 2 because null char
	file_contents = (char *)malloc(2 * sizeof(file_contents));
	int i = 0;
	int ch;
	while (true)
	{
		ch = fgetc(file);
		if (ch < 0) { break; }
		file_contents[i] = ch;
		i++;
		file_contents = (char *)realloc(file_contents, (i + 2) * sizeof(file_contents));
	}
	file_contents[i] = '\0';
	fclose(file);

	return file_contents;
}

void replace_word(char * input_word, char * output_word)
{
	int input_word_len = strlen(input_word);
	int output_word_len = strlen(output_word);
	bool is_matching_word_found = true;
	
	for (int j = 0; j < input_word_len; j++)
	{
		if (!(input_stream[i - j] == input_word[input_word_len - 1 - j]))
		{
			is_matching_word_found = false;
			break;
		}
	}

	if (is_matching_word_found == true)
	{
		output_offset = output_offset + output_word_len - input_word_len;
		output_stream = (char *)realloc(output_stream, (i + output_offset + 2) * sizeof(output_stream));
		for (int j = 0; j < output_word_len; j++)
		{
			output_stream[i + output_offset - j] = output_word[output_word_len - 1  - j];
		}
	}
}

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		printf("error: no input\n");
		return 1;
	}
	
	input_stream = copy_file_to_memory(argv[1]);
	// 2 because null char at the end, and starting char
	output_stream = (char *)malloc(2 * sizeof(output_stream));
	
	while (input_stream[i] != '\0')
	{
		output_stream[i + output_offset] = input_stream[i];
		
		for (int k = 0; k < REPLACEMENT_WORDS_LIST_LEN; k++)
		{
			replace_word(REPLACEMENT_WORDS_LIST[k].esp, REPLACEMENT_WORDS_LIST[k].eng);
		}
		
		i++;
		output_stream = (char *)realloc(output_stream, (i + output_offset + 2) * sizeof(output_stream));
	}
	output_stream[i + output_offset] = '\0';

	printf(output_stream);
	
	free(input_stream);
	free(output_stream);
	return 0;
}
