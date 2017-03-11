#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Challenge#2/list.h"
#include "words.h"

void fill_from_file(list *list, FILE *fp, char **words) {
    char line[1024];
    int n = 0;
    while (fscanf(fp, "%1023s", line) == 1 && !is_separator(line[0])) {
        words[n] = malloc((sizeof(line)));
        strncpy(words[n], line, sizeof(line));
        word_t *found = find(list, words[n]);
        if (found) {
            found->count++;
        } else {
            word_t word = {.word = words[n], .count = 1};
            append(list, &word);
        }
        n++;
    }
};

bool is_separator(char c) {
    return isspace(c) || ispunct(c);
};

word_t *find(list *list, char *word) {
    Node *node = list->head;
    while (node != NULL) {
        word_t *curr = node->data;
        if (strcmp(curr->word, word) == 0) {
            return curr;
        }
        node = node->next;
    }
    return NULL;
};

void sort_list(list *list) {
    Node *tmpPtr = list->head;
    Node *tmpNxt = list->head->next;

    int tmp_count;
    char *tmp_word;

    while (tmpNxt != NULL) {
        while (tmpNxt != tmpPtr) {
            word_t *tmp_word_t = tmpPtr->data;
            word_t *tmpNxt_word_t = tmpNxt->data;
            if (tmpNxt_word_t->count > tmp_word_t->count) {
                tmp_count = tmp_word_t->count;
                tmp_word = tmp_word_t->word;

                tmp_word_t->count = tmpNxt_word_t->count;
                tmp_word_t->word = tmpNxt_word_t->word;

                tmpNxt_word_t->count = tmp_count;
                tmpNxt_word_t->word = tmp_word;
            }
            tmpPtr = tmpPtr->next;
        }
        tmpPtr = list->head;
        tmpNxt = tmpNxt->next;
    }
}