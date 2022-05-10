#include "philosophers.h"

t_philo *create_philos(t_data *data)
{
    int i;
    int j;
    t_philo *philos;

    i = 1;
    j = 0;
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_number);
    philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
    while (i <= data->philos_number)
    {
        philos[j].id = i;
        gettimeofday(&philos[j].last_eat, NULL);
        philos[j].left_hand = data->forks[i];
        philos[j].state = THINKING;
        if (philos[j].id != data->philos_number)
            philos[j].right_hand = data->forks[i + 1];
        else
            philos[j].right_hand = data->forks[(i + 1) % data->philos_number];
        philos[j].data = data;
        i += 1;
        j += 1;
    }
    return (philos);
}

t_philo *setup_state(t_data *data)
{
    int should_eat;

    should_eat = data->philos_number / 2;
    while (should_eat)
    {
        
    }
}

void    start_sim(t_data *data)
{
    int i;
    t_philo *philos;

    i = 0;
    philos = create_philos(data);
    while (i < data->philos_number)
    {
        pthread_create(&philos[i].thread, NULL, philo, &philos[i]);
        i++;
    }
    i = 0;
    while (i < data->philos_number)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}