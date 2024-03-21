/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-alberick.mahoussi
** File description:
** main
*/

#include <stdbool.h>
#include "../include/panoramix.h"

bool is_digit(int ac, char **av)
{
    int i = 0;
    for (i = 0; i < ac; i++) {
        if (atoi(av[i]) < 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1] == "-h") {
        usage();
        exit(0);
    }
    if (argc != 5 || is_digit(argc, argv) == false) {
        usage();
        printf("\nValues must be > 0\n");
        return 84;
    }
    if (argc == 5 && atoi(argv[1]) == 0) {
        usage();
        printf("\nValues Villager must be > 0\n");
        return 84;
    }
    start(argv);
    return 0;
}
