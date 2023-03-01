// list of words to replace an esperanto c word with a normal c word

typedef struct 
{
	char * esp;
	char * eng;
} 
REPLACEMENT_WORD_PAIR;

// be exact or segmentation fault
#define REPLACEMENT_WORDS_LIST_LEN 6

REPLACEMENT_WORD_PAIR REPLACEMENT_WORDS_LIST[REPLACEMENT_WORDS_LIST_LEN] = 
{
	// macros
	{"#inkludu", "#include"},
	{"#difinu", "#define"},
	// data types
	{"ent", "int"},
	// functions
	{"cxefa", "main"},
	{"presuf", "printf"},
	// other
	{"revenu", "return"}
};
