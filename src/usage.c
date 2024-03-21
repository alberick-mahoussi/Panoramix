/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-alberick.mahoussi
** File description:
** usage
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/panoramix.h"

void usage(void)
{
    printf(
    "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>");
}

void end_file(panoramix_t *pr, int index)
{
    pr->dm_vilgrs++;
    if (pr->nb_villagers == pr->dm_vilgrs)
        pthread_cond_signal(&pr->druid_cond);
    printf("Villager %d: I'm going to sleep now.\n", index);
}
