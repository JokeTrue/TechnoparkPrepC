#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef void (*freeFunction)(void *);

typedef bool (*listIteratorFn)(void *);

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    int length;
    size_t elSize;
    Node *head;
    Node *tail;
    freeFunction free;
} list;

void create_list(list *list, size_t elSize, freeFunction free);

void destroy(list *list);

void prepend(list *list, void *el);

void append(list *list, void *el);

int list_size(list *list);

void fn_for_each(list *list, listIteratorFn fn);


#endif
