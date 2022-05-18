#include "philosophers.h"

void    check(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_philo_dies, philo);
    pthread_detach(thread);
    if (philo->data->must_eat_number != 0)
    {
        pthread_create(&thread, NULL, check_philo_dies, philo);
        pthread_detach(thread);
    }
}

void    create_philos(t_data *data)
{
    int j;
    pthread_t thread;

    j = 0;
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_number);
    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
    while (j < data->philos_number)
    {
        pthread_mutex_init(&data->finshed_state, NULL);
        pthread_mutex_init(&data->forks[j], NULL);
        data->philos[j].id = j + 1;
        data->philos[j].last_eat = ft_gettimeday();
        data->philos[j].left_hand = data->forks[j];
        if (data->philos[j].id != data->philos_number)
            data->philos[j].right_hand = data->forks[j + 1];
        else
            data->philos[j].right_hand = data->forks[(j + 1) % data->philos_number];
        data->philos[j].data = data;
        check(&data->philos[j]);
        j += 1;
    }
}

void    start_sim(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        pthread_create(&data->philos[i].thread, NULL, philo, &data->philos[i]);
        i++;
    }
    i = 0;
    while (i < data->philos_number)
    {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
}