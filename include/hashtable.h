/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct data_s {
    int hashed_value;
    char *name;
} data_t;

typedef struct secu_linked_list_s {
    data_t data;
    struct secu_linked_list_s *previous;
    struct secu_linked_list_s *next;
} secu_linked_list_t;

typedef struct hashtable_s {
    secu_linked_list_t *head;
    secu_linked_list_t *tail;
    int global_size;
    int (*hash)(char *, int);
} hashtable_t;

// Hash function
int hash(char *key, int len);

int my_hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int my_hash(char *key, int len);

    #define UNUSED __attribute__((unused))
#endif /* HASHTABLE_H */
