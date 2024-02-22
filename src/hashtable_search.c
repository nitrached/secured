/*
** EPITECH PROJECT, 2024
** secured_w_manech
** File description:
** hashtable_search
*/

#include "my.h"
#include "hashtable.h"
#include <stddef.h>

static char *browse_line(int hashed_srch, secu_linked_list_t *tmp)
{
    while (tmp != NULL) {
        if (hashed_srch == tmp->data.hashed_value)
            return (tmp->data.name);
        tmp = tmp->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed_srch;
    int index;
    secu_linked_list_t *tmp = NULL;
    char *return_value = NULL;

    if (ht == NULL || key == NULL)
        return NULL;
    hashed_srch = ht[0].hash(key, ht[0].global_size);
    index = hashed_srch % ht[0].global_size;
    tmp = ht[index].head;
    if (tmp != NULL) {
        return_value = browse_line(hashed_srch, tmp);
    }
    return return_value;
}
