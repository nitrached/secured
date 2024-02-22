/*
** EPITECH PROJECT, 2024
** secured_w_manech
** File description:
** new_hashtable
*/

#include "my.h"
#include "hashtable.h"
#include <stddef.h>
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_table = malloc(sizeof(hashtable_t) * (len + 1));

    if (len < 0)
        return NULL;
    for (int i = 0; i < len; i++) {
        new_table[i].head = NULL;
        new_table[i].tail = NULL;
        new_table[i].hash = hash;
        new_table[i].global_size = len;
    }
    return new_table;
}
