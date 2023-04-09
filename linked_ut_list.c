#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"utlist.h"

typedef struct element {
    char *name;
    struct element *prev; /* needed for a doubly-linked list only */
    struct element *next; /* needed for singly- or doubly-linked lists */
} element;

int namecmp(element* a, element* b) {
    return strcmp(a->name, b->name);
}
#define LL_PRINT_ALL(head, el) \
    printf("---\n");\
    LL_FOREACH(head, el) printf(" %s =>", el->name); \
    printf("---\n");

#define LL_CREATE_ELEM(e, n) \
    e = malloc(sizeof(element)); \
    e->name = n; \
    e->next = NULL;

#define LL_ADD_ALL(head, e, array, i, size) \
    for (i=0; i<size; i++) { \
        LL_CREATE_ELEM(e,array[i]); \
        LL_APPEND(head, e); \
    }

int main() {
    element *head1 = NULL, *head2 = NULL, *e = NULL, *like = NULL;
    char* array[5]={"Name1", "Name2", "Name3", "Name4", "Name5"};
    int i;

    LL_ADD_ALL(head1, e, array, i, 5);
    LL_PRINT_ALL(head1, e);
}