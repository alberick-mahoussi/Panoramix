/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-alberick.mahoussi
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <semaphore.h>
    #define villager_try_drink (printf \
    ("Villager %d: I need a drink... I see %d servings left.\n"\
    , index, pr.pot_use))
    #define villager_sleeping (printf \
    ("Villager %d: I'm going to sleep now.\n", index), \
    pr.villagers_left--)
    #define fight_roman (printf \
    ("Villager %d: Take that roman scum! Only %d left.\n",\
    index, (fight - 1)))

    typedef struct panoramix_thread {
        int nb_villagers;
        int pot_size;
        int nb_fights;
        int nb_refills;
        int pot_use;
        int dm_vilgrs;
        int villagers_left;
        pthread_mutex_t mutex;
        pthread_mutex_t mutex_druid;
        pthread_cond_t druid_cond;
        pthread_cond_t cond_villagers;
    } panoramix_t;

    void usage(void);
    int start(char **argv);
    void end_file(panoramix_t *pr, int index);
#endif /* !PANORAMIX_H_ */
