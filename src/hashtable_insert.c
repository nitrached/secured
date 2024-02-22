/*
** EPITECH PROJECT, 2024
** secured_w_manech
** File description:
** hashtable_insert
*/
#include "my.h"
#include "hashtable.h"
#include <stddef.h>
#include <stdlib.h>

static char *change_line(int hashed_srch, secu_linked_list_t *tmp, char *value)
{
    while (tmp != NULL) {
        if (hashed_srch == tmp->data.hashed_value) {
            free(tmp->data.name);
            tmp->data.name = my_strdup(value);
            return (tmp->data.name);
        }
        tmp = tmp->next;
    }
    return NULL;
}

static int replace_value(hashtable_t *ht, char *value, char *key)
{
    int hashed_srch;
    int index;
    secu_linked_list_t *tmp = NULL;
    char *return_value = NULL;

    if (ht == NULL || key == NULL)
        return 0;
    hashed_srch = ht[0].hash(key, ht[0].global_size);
    index = hashed_srch % ht[0].global_size;
    tmp = ht[index].head;
    if (tmp != NULL) {
        change_line(hashed_srch, tmp, value);
    }
    return 1;
}

static int insert(hashtable_t *ht, char *key, char *value)
{
    int hashed = ht[0].hash(key, ht[0].global_size);
    int index = hashed % ht[0].global_size;
    secu_linked_list_t *new_node = NULL;

    new_node = malloc(sizeof(secu_linked_list_t));
    new_node->next = ht[index].head;
    new_node->previous = NULL;
    new_node->data.hashed_value = hashed;
    new_node->data.name = my_strdup(value);
    if (new_node->next == NULL)
        ht[index].tail = new_node;
    if (new_node->next != NULL)
        new_node->next->previous = new_node;
    ht[index].head = new_node;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    if (ht == NULL || ht[0].global_size == 0 || key == NULL || value == NULL)
        return 84;
    if (ht_search(ht, key) != NULL) {
        if (!replace_value(ht, value, key))
            return 84;
        return 0;
    }
    insert(ht, key, value);
    return 0;
}
