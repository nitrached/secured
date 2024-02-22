/*
** EPITECH PROJECT, 2024
** secured_w_manech
** File description:
** hash
*/

#include "my.h"
#include "hashtable.h"
#include <stdio.h>

int hash(char *key, int len)
{
    unsigned int seed = 0;
    unsigned long long squared;
    unsigned int middleDigits;

    for (int i = 0; i < len; ++i) {
        seed = seed * 31 + key[i % len];
    }
    squared = (unsigned long long)seed * seed;
    middleDigits = (squared / 100) % 1000;
    return middleDigits;
}
