// reads an esperanto-fied c file, printfs it out as a normal c file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "words.h"

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

int main(int argc, char ** argv)
{
	/* command line */
	if (argc < 2)
	{
		printf("error: no input\n");
		
		return 1;
	}
	
	char * input = copy_file_to_memory(argv[1]);
	// go through each word at `i`
	int i = 0;
	while (true)
	{
		if (i == WORDS_LIST_LEN) { break; }
		
		// go through each character at `j`
		int j = 0;
		while (true)
		{
			if (input[j] == '\0') { break; }
			
			// check if word matches
			bool word_match_flag = false;
			int k = 0;
			while (true)
			{
				if (k == WORDS_LIST[i].eol) { word_match_flag = true; break; }

				if (input[j + k] == '\0') { break; }
				if (WORDS_LIST[i].eo[k] != input[j + k]) { break; }

				k++;
			}

			if (word_match_flag == true)
			{
				int diff = WORDS_LIST[i].enl - WORDS_LIST[i].eol;
				/* when the words aren't the same length */
				if (diff != 0)
				{
					//FIXME `input_len`
					int input_len;
					if (diff > 0)
					{
						input = (char *)realloc(input, input_len + diff * sizeof(input));
					}
					int k = 0;
					while (true)
					{
						input[j + k] =
						input[j + WORDS_LIST[i].enl + k];
						
						if (input[j + WORDS_LIST[i].enl + diff + k] == '\0') 
						{
							input_len = j + WORDS_LIST[i].enl + diff + k;
							break;
						}
						
						k++;
					}
					if (diff < 0)
					{
						input = (char *)realloc(input, input_len + diff * sizeof(input));
					}
				}
				
				int k = 0;
				while (true)
				{
					if (k == WORDS_LIST[i].enl) { break; }
					
					input[j + k] = WORDS_LIST[i].en[k];
					
					k++;
				}
			}

			j++;
		}

		i++;
	}

	printf("%s", input);

	free(input);
	return 0;
}
