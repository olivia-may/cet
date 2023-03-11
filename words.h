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
 * list of words to replace an esperanto c word with a normal c word
 */

#ifndef WORDS_H
#define WORDS_H

// be exact or segmentation fault
#define WORDS_LIST_LEN 6

typedef struct
{
	char * str;
	int len;
}
word;

typedef struct 
{
	word eo;
	word en;
} 
WORDS;

WORDS WORDS_LIST[WORDS_LIST_LEN] = 
{
	// '#' words
	{"#inkludu", 8, "#include", 8},
	{"#difinu", 7, "#define", 7},
	// data types
	{"ent", 3, "int", 3},
	// functions
	{"cxefa", 5, "main", 4},
	{"presuf", 6, "printf", 6},
	// other
	{"revenu", 6, "return", 6}
};

#endif
