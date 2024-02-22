/*
** EPITECH PROJECT, 2024
** secured
** File description:
** main
*/
#include "my.h"
#include "hashtable.h"
#include <stddef.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    hashtable_t *ht = NULL;

    ht = new_hashtable(&my_hash, 5);
    ht_insert(ht, "01", "f");
    ht_insert(ht, "02", "RobotMovementControl.c");
    ht_insert(ht, "03", "TargetAcquisitionModule.java");
    ht_insert(ht, "04", "DefensiveStrategies.R");
    ht_insert(ht, "05", "OffensiveTactics.ml");
    ht_insert(ht, NULL, "hello");
    printf("Looking for \"%s\": \"%s\"\n", "Kratos", ht_search(ht, NULL));
    ht_delete(ht, "08");
    //ht_dump(ht);
    ht_insert(ht, "05", "OffensiveTactics..........ml");
    ht_dump(ht);
    return 0;
}
