#ifndef _WORDS_H_
#define _WORDS_H_

#include <stdio.h>
#include "../Challenge#2/list.h"

typedef struct word {
    char *word;
    int count;
} word_t;

void fill_from_file(list *list, FILE *fp, char **words);

bool is_separator(char c);

word_t *find(list *list, char *word);

void sort_list(list *list);

#endif
