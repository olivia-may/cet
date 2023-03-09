// list of words to replace an esperanto c word with a normal c word
#ifndef WORDS_H
#define WORDS_H

// be exact or segmentation fault
#define WORDS_LIST_LEN 6

typedef struct 
{
	char * eo; // word
	int eol; // word len
	char * en;
	int enl;
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
