#include "philosophers.h"

void    thinking(int period)
{
    usleep(period * 1000);
}

void    *philo(void *data)
{
    // printf("Printing something\n");
    printf("Philo %d Can eat for: %d Started: %ld\n", (int)((t_philo *)data)->id, (int)((t_philo *)data)->data->time_to_eat, (long)((t_philo *)data)->last_eat.tv_sec);
    return NULL;
}