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

#define LL_FIND_INDEX(head, e, counter, index) \
    (e) = head; \
    for (counter=0; counter<index; counter++) { \
        if (!(e)) { \
            fprintf(stderr, "%s\n", "Index Out of Bounds"); \
            exit(EXIT_FAILURE); \
        } \
        (e) = (e)->next; \
    }   

#define LL_ADD_INDEX(head, e, counter, index, e1, val) \
    LL_FIND_INDEX(head, e, counter, index) \
    LL_CREATE_ELEM(e1, val); \
    LL_PREPEND_ELEM(head, e, e1);

#define LL_INDEX_OF(head, e, index, val) \
    index = 0; \
    LL_FOREACH(head, e) { \
        if (e->name == val) break; \
        index++; \
    }    

#define LL_GET_FIRST_VAL(head, val_dest) \
    if (head1) strcpy(val_dest, head->name);

#define LL_GET_LAST(head, e) \
    e = NULL; \
    LL_FOREACH(head, e) { \
        if (e->next == NULL) break; \
    }

#define LL_REMOVE_FIRST(head) \
    LL_DELETE(head, head)

#define LL_REMOVE_LAST(head, e) \
    LL_GET_LAST(head, e) \
    LL_DELETE(head, e)

#define LL_REMOVE_VAL(head, e, val) \
    LL_SEARCH_SCALAR(head, e, name, val); \
    if (e) LL_DELETE(head, e);

#define LL_CLEAR(head, e, tmp) \
    LL_FOREACH_SAFE(head, e, tmp) { \
        LL_DELETE(head, e); \
    }

#define LL_LAST_INDEX_OF(head, e, val, counter, index) \
    counter = 0; \
    LL_FOREACH(head, e) { \
        if (e->name == val) { \
            index = counter; \
        } \
        counter++; \
    }

#define LL_CLONE(head, e, tmp, dest) \
    LL_FOREACH_SAFE(head, e, tmp) { \
        LL_APPEND(dest, e); \
    }

int main() {
    element *head1 = NULL, *head2 = NULL, *e = NULL, *e1 = NULL;
    char* array[5]={"Name1", "Name2", "Name3", "Name4", "Name5"};
    int i;
    char dest[40] = {0};

    LL_GET_FIRST_VAL(head1, dest);
    if (dest) printf("%s\n", dest);
    
    LL_ADD_INDEX(head1, e, i, 0, e1, "Name7");
    LL_PRINT_ALL(head1, e);
    LL_ADD_INDEX(head1, e, i, 0, e1, "Name9");
    LL_PRINT_ALL(head1, e);

    LL_ADD_ALL(head1, e, array, i, 5);
    LL_PRINT_ALL(head1, e);
    LL_ADD_INDEX(head1, e, i, 3, e1, "Name6");
    LL_PRINT_ALL(head1, e);

    LL_INDEX_OF(head1, e, i, "Name6");
    printf("%d\n", i);

    LL_GET_FIRST_VAL(head1, dest);
    if (dest) printf("%s\n", dest);

    LL_GET_LAST(head1, e);
    if (e) printf("%s\n", e->name);

    LL_REMOVE_FIRST(head1);
    LL_PRINT_ALL(head1, e);

    LL_REMOVE_LAST(head1, e);
    LL_PRINT_ALL(head1, e);

    LL_SEARCH_SCALAR(head1, e, name, "Name1");
    if (e) printf("%s\n", e->name);

    LL_REMOVE_VAL(head1, e, "Name1");
    LL_PRINT_ALL(head1, e);

    // LL_CLEAR(head1, e, e1);
    // LL_PRINT_ALL(head1, e);

    int index = -1;
    LL_LAST_INDEX_OF(head1, e, "Name4", i, index);
    LL_COUNT(head1, e, i);
    printf("%d\n", index);

    LL_CLONE(head1, e, e1, head2);
    LL_PRINT_ALL(head2, e)
}