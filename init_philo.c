#include "philosophers.h"

void    init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
}

void    create_philos(t_data *data)
{
    int j;

    j = 0;
    data->start_time = ft_gettimeday();
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_number);
    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
    init_forks(data);
    while (j < data->philos_number)
    {
        data->philos[j].id = j + 1;
        data->philos[j].eat_number = 0;
        data->philos[j].last_eat = data->start_time;
        data->philos[j].left_hand = &data->forks[j];
        if (data->philos[j].id != data->philos_number)
            data->philos[j].right_hand = &data->forks[j + 1];
        else
            data->philos[j].right_hand = &data->forks[(j + 1) % data->philos_number];
        data->philos[j].data = data;
        j += 1;
    }
}

void    check_philo_dead(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        if (check_philo_dies(&data->philos[i]))
            break ;
        i++;
        if (i == data->philos_number)
        {
            if (check_end_simulation(data))
                exit(0);
            i = 0;
        }
    }
}

void    start_sim(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        pthread_create(&data->philos[i].thread, NULL, philo, &data->philos[i]);
        pthread_detach(data->philos[i].thread);
        i++;
    }
    check_philo_dead(data);
}