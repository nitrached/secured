/*
** EPITECH PROJECT, 2024
** secured
** File description:
** generate_insert
*/

#include <stdio.h>

void generer_lignes() {
    for (int i = 1000; i < 2000; i++) {
        printf("ht_insert(ht, \"<%d>\", \"hello\");\n", i + 1);
    }
}

int main() {
    generer_lignes();
    return 0;
}
