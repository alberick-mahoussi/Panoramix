/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-alberick.mahoussi
** File description:
** panoramix
*/

#include "../include/panoramix.h"

static panoramix_t pr =
{
    .pot_use = 0,
    .mutex = PTHREAD_MUTEX_INITIALIZER,
    .mutex_druid = PTHREAD_MUTEX_INITIALIZER,
    .cond_villagers = PTHREAD_COND_INITIALIZER,
    .druid_cond = PTHREAD_COND_INITIALIZER,
    .nb_fights = 0,
    .pot_size = 0,
    .nb_refills = 0,
    .nb_villagers = 0
};

void insert_data(char **av)
{
    pr.nb_villagers = atoi(av[1]);
    pr.pot_size = atoi(av[2]);
    pr.nb_fights = atoi(av[3]);
    pr.nb_refills = atoi(av[4]);
    pr.pot_use = pr.pot_size;
    pr.villagers_left = pr.nb_villagers;
}

static void *druit_function(void *druid_th)
{
    printf("Druid: I'm ready... but sleepy...\n");
    while (pr.nb_refills > 0) {
        pthread_mutex_lock(&pr.mutex_druid);
        while (pr.pot_use > 0 && pr.villagers_left > 0)
            pthread_cond_wait(&pr.druid_cond, &pr.mutex_druid);
        if (pr.nb_refills == 0)
            break;
        pr.pot_use = pr.pot_size;
        pthread_mutex_unlock (&pr.mutex_druid);
        pr.nb_refills--;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
        printf("Beware I can only make %d more", (pr.nb_refills));
        printf(" refills after this one.\n");
        pthread_cond_broadcast(&pr.cond_villagers);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

void callback_druid(panoramix_t *pr, int index, int fight)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", index);
    if (pthread_mutex_trylock(&pr->mutex_druid) == 0) {
        pthread_cond_signal(&pr->druid_cond);
        pthread_cond_wait(&pr->cond_villagers, &pr->mutex_druid);
        pr->pot_use--;
        pthread_mutex_unlock(&pr->mutex_druid);
    } else {
        pthread_cond_wait(&pr->cond_villagers, &pr->mutex_druid);
    }
    fight_roman;
    pthread_mutex_unlock(&pr->mutex);
}

static void *villagers_function(void *villager_th)
{
    int index = (int)villager_th;
    int fight = pr.nb_fights;
    printf ("Villager %d: Going into battle!\n", index);
    for (int i = 0; i != fight; fight--) {
        pthread_mutex_lock(&pr.mutex);
        villager_try_drink;
        if (pr.pot_use == 0 && pr.nb_refills > 0) {
            callback_druid(&pr, index, fight);
            break;
        } if (pr.pot_use > 0) {
            pr.pot_use--;
        } else {
            pthread_mutex_unlock(&pr.mutex);
            villager_sleeping;
            return (NULL);
        }
        fight_roman;
        pthread_mutex_unlock(&pr.mutex);
    }
    villager_sleeping;
}

int start(char **av)
{
    insert_data(av);
    int v = 0;
    pthread_t dru;
    pthread_t villagers[pr.nb_villagers];
    if (v = pthread_create(&dru, NULL, druit_function, (void *)&pr) == 0) {
        for (int i = 0; i < pr.nb_villagers; i++) {
            v = pthread_create(&villagers[i], NULL, villagers_function, \
            (void *)i);
            (v != 0) ? fprintf(stderr, "%s", strerror(v)) : 0;
        }
    } else
        fprintf(stderr, "%s", strerror(v));
    for (int i = 0; i < pr.nb_villagers; i++)
        pthread_join(villagers[i], NULL);
    pthread_join(dru, NULL);
    return 0;
}
