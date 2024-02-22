/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hashtable_delete
*/
#include "my.h"
#include "hashtable.h"
#include <stddef.h>
#include <stdlib.h>

static void delete_linked_list(secu_linked_list_t *tmp)
{
    while (tmp != NULL) {
        if (tmp->previous != NULL) {
            free(tmp->previous);
        }
        free(tmp->data.name);
        if (tmp->next == NULL) {
            free(tmp);
            break;
        }
        tmp = tmp->next;
    }
}

void delete_hashtable(hashtable_t *ht)
{
    secu_linked_list_t *tmp;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht[0].global_size; i++) {
        tmp = ht[i].head;
        delete_linked_list(tmp);
        ht[i].head = NULL;
        ht[i].tail = NULL;
    }
    ht[0].global_size = 0;
    ht = NULL;
    free(ht);
}
