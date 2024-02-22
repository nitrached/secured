/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete_node
*/
#include "my.h"
#include "hashtable.h"
#include <stddef.h>

static void del_node(secu_linked_list_t *current, hashtable_t *ht, int i)
{
    if (current->previous == NULL && current->next == NULL) {
        ht[i].head = NULL;
        ht[i].tail = NULL;
        return;
    }
    if (current->previous == NULL) {
        ht[i].head = current->next;
        ht[i].head->previous = NULL;
    } else if (current->next == NULL) {
        ht[i].tail = current->previous;
        current->previous->next = NULL;
    } else {
        current->next->previous = current->previous;
        current->previous->next = current->next;
    }
}

static char *browse_line(int hashed_srch,
    secu_linked_list_t *tmp, hashtable_t *ht, int i)
{
    char *name = NULL;

    while (tmp != NULL) {
        name = my_strdup(tmp->data.name);
        if (hashed_srch == tmp->data.hashed_value) {
            del_node(tmp, ht, i);
            return name;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int my_ht_delete(hashtable_t *ht, char *key)
{
    int hashed_srch = ht[0].hash(key, ht[0].global_size);
    secu_linked_list_t *tmp = NULL;
    char *return_value = NULL;

    for (int i = 0; i < ht[0].global_size; i++) {
        tmp = ht[i].head;
        return_value = browse_line(hashed_srch, tmp, ht, i);
        if (return_value != NULL) {
            return 0;
        }
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (ht == NULL || ht[0].global_size == 0 || key == NULL) {
        return 84;
    }
    if (my_ht_delete(ht, key) == 84)
        return 84;
    return 0;
}
