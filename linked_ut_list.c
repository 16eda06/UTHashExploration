#include<stdio.h>
#include<stdlib.h>
#include"utlist.h"

typedef struct element {
    char *name;
    struct element *prev; /* needed for a doubly-linked list only */
    struct element *next; /* needed for singly- or doubly-linked lists */
} element;

element* new_node(char* name) {
    element* new = malloc(sizeof(element));
    new->name = name;
    return new;
}

int main() {
    element *head1 = NULL, *head2 = NULL, *e = NULL;
    element *new1 = new_node("Name1");
    element *new2 = new_node("Name2");
    element *new3 = new_node("Name3");
    element *new4 = new_node("Name4");

    LL_PREPEND(head1, new1);
    LL_PREPEND(head1, new2);
    LL_FOREACH(head1, e) printf("(%p,%s) ->\n", e, e->name);

    LL_PREPEND(head2, new3);
    LL_PREPEND(head2, new4);
    LL_FOREACH(head1, e) printf("(%p,%s) ->\n", e, e->name);

    LL_CONCAT(head1, head2);

    e = NULL;
    LL_SEARCH_SCALAR(head1, e, name, "Name2");
    if (e)
        printf("%s", e->name);

}