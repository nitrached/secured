/*
** EPITECH PROJECT, 2024
** secured_w_manech
** File description:
** hashtable_dump
*/
#include "my.h"
#include "hashtable.h"
#include <stddef.h>
#include <unistd.h>

void ht_dump(hashtable_t *ht)
{
    secu_linked_list_t *tmp;

    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht[0].global_size; i++) {
        tmp = ht[i].head;
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        while (tmp != NULL) {
            my_putstr("> ");
            my_put_nbr(tmp->data.hashed_value);
            my_putstr(" - ");
            write(1, tmp->data.name, my_strlen(tmp->data.name));
            write(1, "\n", 1);
            tmp = tmp->next;
        }
    }
}
