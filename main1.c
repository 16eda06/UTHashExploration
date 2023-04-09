#include"uthash.h"
#include<stdio.h>

struct my_struct {
    int key;            /* we'll use this field as the key */
    char value[10];
    UT_hash_handle hh; /* makes this structure hashable */
};
typedef struct my_struct ms;

ms *my_hash_table = NULL;

void add_user(ms *s) {
    HASH_ADD_INT( my_hash_table, key, s );
}

ms *find_user(int user_id) {
    ms *s;

    HASH_FIND_INT( my_hash_table, &user_id, s );
    return s;
}

void delete_user(ms *user) {
    HASH_DEL( my_hash_table, user);
}

int main() {
    char buf[10] = "a";
    ms* new_user;
    new_user = (ms*) malloc(sizeof(ms)*10);
    new_user->key = 10;
    strcpy(new_user->value, "abc");
    add_user(new_user);
    ms* find_user_val = find_user(new_user->key);
    printf("\n%s", find_user_val->value);
}