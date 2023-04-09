#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

struct list_node {
    int val;
    struct list_node *next;
};

typedef struct list_node lnode;

// LL_PRINT_ALL
void print_list(lnode* temp) {
    // printf("Begin\n");
    while (temp != NULL)
    {
        printf("(%p,%d) ->\n", temp, temp->val);
        // printf("(%d) ->", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// LL_PREPEND
void add_first(lnode** head, int v) {
    lnode* new = malloc(sizeof(lnode));
    new->val = v;
    new->next = *head;
    *head = new;
}

// LL_APPEND
void add_last(lnode** head, int v) {
    lnode* new = malloc(sizeof(lnode));
    new->val = v;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }

    lnode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return;
}

// LL_ADD_ALL
void add_all(lnode** head, int* array, int size_of_array) {
    int i=0;
    for(;i<size_of_array;i++) {
        add_last(head, array[i]);
    }
}

// LL_ADD_INDEX
/*
returns 0 in case of success, -1 otherwise
*/
int add_index(lnode** head, int index, int v) {
    if (index == 0) {
        add_first(head, v);
        return 1;
    }

    if (*head == NULL) {
        return 0;
    }

    lnode* temp = *head;
    lnode *new = NULL;
    int i = 1;
    while (temp->next != NULL)
    {
        if (i == index) {
            new = malloc(sizeof(lnode));
            new->val = v;
            new->next = temp->next;
            temp->next = new;
            return 1;
        }
        temp = temp->next;
        i++;
    }
    
    if (i == index) {
        new = malloc(sizeof(lnode));
        new->val = v;
        new->next = temp->next;
        temp->next = new;
        return 1;
    }

    return 0;
}

// LL_INDEX_OF
int index_of(lnode* head, int val) {
    int i=0;
    while (head != NULL)
    {
        if (head->val == val) {
            return i; 
        }
        i++;
        head = head->next;
    }
    return -1;
}

// LL_GET_FIRST_VAL
int get_first(lnode* head) {
    if (head == NULL)
        return INT_MIN;
    return head->val;
}

// LL_GET_LAST
int get_last(lnode* head) {
    if (head == NULL) {
        return INT_MIN;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    return head->val;
}

// LL_REMOVE_FIRST
int remove_first(lnode** head) {
    if (head == NULL)
        return INT_MIN;
    lnode *temp = *head;
    int v = temp->val;
    (*head) = (*head)->next;
    free(temp);    
    return v;
} 

// LL_REMOVE_LAST
int remove_last(lnode** head) {
    if (*head == NULL) {
        return INT_MIN;
    }

    lnode *temp = *head;
    if (temp->next == NULL) {
        int v = temp->val;
        free(temp);
        *head = NULL;
        return v;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    int v = temp->next->val;
    free(temp->next);
    temp->next = NULL;
    return v;    
}

// LL_SEARCH_SCALAR
int contains(lnode *head, int val) {
    return index_of(head, val) != -1;
}

// LL_COUNT
int size(lnode *head) {
    int size=0;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }
    return size;
}

// LL_REMOVE_VAL
/*
returns index if `v` is removed from the list
*/
int remove_val(lnode** head, int v) {
    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == v) {
        remove_first(head);
        return 0;
    }

    lnode* temp = *head;
    int index = 1;
    while (temp->next->next != NULL)
    {
        if (temp->next->val == v) {
            break;
        }
        temp = temp->next;
        index++;
    }
    
    if (temp->next->val == v) {
        // free(temp->next);
        temp->next = temp->next->next;
        return index;
    }

    return -1;
}

// LL_CLEAR
void clear(lnode **head) {
    int s = size(*head);
    while (s>0) {
        remove_last(head);
        s--;
    }    
}

// LL_LAST_INDEX_OF
int last_index_of(lnode *head, int v) {
    int index = -1, i = 0;

    while (head != NULL)
    {
        if (head->val == v) {
            index = i;
        }
        i++;
        head = head->next;
    }

    return index;    
}

// LL_CLONE
void clone(lnode* src, lnode** dest) {
    while (src != NULL)
    {
        add_last(dest, src->val);
        src = src->next;
    }
}

int main() {
    lnode *head = NULL, *head1 = NULL;
    int array[5] = {10,20,30,40,50};
    int i=0;
    
    for (;i<5;i++) {
        add_index(&head, i, array[i]);
    }
}
