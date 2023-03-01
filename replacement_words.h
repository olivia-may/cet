// list of words to replace an esperanto c word with a normal c word

typedef struct 
{
	char * esp;
	char * eng;
} 
REPLACEMENT_WORD_PAIR;

// be exact or segmentation fault
#define REPLACEMENT_WORDS_LIST_LEN 9

REPLACEMENT_WORD_PAIR REPLACEMENT_WORDS_LIST[REPLACEMENT_WORDS_LIST_LEN] = 
{
	{"tiu cxi", "this"},
	{"testo", "test"},
	{"estas", "is a"},
	{"#inkludu", "#include"},
	{"#difinu", "#define"},
	{"ent", "int"},
	{"cxefa", "main"},
	{"presuf", "printf"},
	{"revenu", "return"}
};
