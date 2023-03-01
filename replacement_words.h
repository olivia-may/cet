// list of words to replace an esperanto c word with a normal c word

// be exact or segmentation fault
#define REPLACEMENT_WORDS_LIST_LEN 3

typedef struct 
{
	char * esp;
	char * eng;
} 
REPLACEMENT_WORD_PAIR;

REPLACEMENT_WORD_PAIR REPLACEMENT_WORDS_LIST[REPLACEMENT_WORDS_LIST_LEN] = 
{
	{"tiu cxi", "this"},
	{"testo", "test"},
	{"estas", "is a"}
};
