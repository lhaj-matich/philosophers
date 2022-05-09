#include "philosophers.h"

void    create_philos(t_data *data)
{
    int i;
    int j;

    i = 1;
    j = 0;
    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_number);
    while (i <= data->philos_number)
    {
        data->philos[j].id = i;
        gettimeofday(&data->philos[j].last_eat, NULL);
        data->philos[j].left_hand = data->forks[i];
        if (data->philos[j].id != data->philos_number)
            data->philos[j].right_hand = data->forks[i + 1];
        else
            data->philos[i].right_hand = data->forks[(i + 1) % data->philos_number];
        i =+ 1;
        j =+ 1;
    }
}

void    start_sim(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        pthread_create(data->philos[i].thread, NULL, philo, &data->philos[i]);
        i++;
    }
    while (i < data->philos_number)
    {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
}