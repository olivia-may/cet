/*
 * cet - C-a Esperanta Tradukisto
 * Copyright (C) 2023 Olivia May - olmay@tuta.io
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * reads an esperanto-fied c file, printfs it out as a normal c file
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "words.h"

word copy_file_to_memory(char * dir)
{
	FILE * file = fopen(dir, "r");
	word file_contents;
	file_contents.str = NULL;
	// 2 because null char
	file_contents.str = (char *)malloc(2 * sizeof(file_contents.str));
	int i = 0;
	int ch;
	while (true)
	{
		ch = fgetc(file);
		if (ch < 0) { break; }
		file_contents.str[i] = ch;
		i++;
		file_contents.str = (char *)realloc(file_contents.str, (i + 2) * sizeof(file_contents.str));
	}
	file_contents.str[i] = '\0';
	file_contents.len = i;
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
	
	word input = copy_file_to_memory(argv[1]);
	word native_word, transl_word;
	// go through each word at `i`
	int i = 0;
	while (true)
	{
		if (i == WORDS_LIST_LEN) { break; }
		
		native_word = WORDS_LIST[i].eo;
		transl_word = WORDS_LIST[i].en;

		// go through each character at `j`
		int j = 0;
		while (true)
		{
			if (input.str[j] == '\0') { break; }
			
			// check if word matches
			bool word_match_flag = false;
			int k = 0;
			while (true)
			{
				if (k == native_word.len) { word_match_flag = true; break; }

				if (input.str[j + k] == '\0') { break; }
				if (native_word.str[k] != input.str[j + k]) { break; }

				k++;
			}

			if (word_match_flag == true)
			{
				int diff = transl_word.len - native_word.len;
				/* when the words aren't the same length */	
				if (diff < 0)
				{
					int l = 0;
					while (true)
					{
						if (l == -diff) break;
						
						k = 0;
						while (true)
						{
							input.str[j + transl_word.len - 1 + k] = input.str[j + transl_word.len + k];

							if (input.str[j + transl_word.len + k] == '\0') break;

							k++;
						}
						
						l++;
					}
					
					input.len += diff;
					input.str = (char *)realloc(input.str, input.len * sizeof(input.str));
				}
				if (diff > 0)
				{
					input.len += diff;
					input.str = (char *)realloc(input.str, input.len * sizeof(input.str));
					
					int l = 0;
					while (true)
					{
						if (l == diff) break;
						
						k = 0;
						while (true)
						{
							input.str[input.len - k] = input.str[input.len - k - 1];

							if (input.len - k - 1 == j) break;

							k++;
						}
						
						l++;
					}
				}
				
				k = 0;
				while (true)
				{
					if (k == transl_word.len) break;

					input.str[j + k] = transl_word.str[k];
					
					k++;
				}
			}

			j++;
		}

		i++;
	}

	printf("%s", input.str);

	free(input.str);
	return 0;
}
