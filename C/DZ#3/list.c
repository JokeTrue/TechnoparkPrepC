#include <wchar.h>
#include <assert.h>
#include <memory.h>
#include "list.h"

void create_list(list *list, size_t elSize, freeFunction free) {
    assert(elSize > 0);
    list->length = 0;
    list->elSize = elSize;
    list->head = list->tail = NULL;
    list->free = free;
}

void destroy(list *list) {
    Node *curr;
    while (list->head != NULL) {
        curr = list->head;
        list->head = curr->next;

        if (list->free) {
            list->free(curr->data);
        }

        free(curr->data);
        free(curr);
    }
}

void prepend(list *list, void *el) {
    Node *node = malloc(sizeof(Node));
    node->data = malloc(list->elSize);
    memcpy(node->data, el, list->elSize);

    node->next = list->head;
    list->head = node;

    if (!list->tail) {
        list->tail = list->head;
    }

    list->length++;
}

void append(list *list, void *el) {
    Node *node = malloc(sizeof(Node));
    node->data = malloc(list->elSize);
    node->next = NULL;

    memcpy(node->data, el, list->elSize);

    if (list->length == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;

}

int list_size(list *list) {
    return list->length;
}

void fn_for_each(list *list, listIteratorFn fn) {
    assert(fn != NULL);

    Node *node = list->head;
    bool result = true;
    while (node != NULL && result) {
        result = fn(node->data);
        node = node->next;
    }
}