#include "philosophers.h"

int check_philo_dies(t_philo *philo)
{
    long long timestamp;


    while (philo->data->finished != 1)
    {
        timestamp = ft_gettimeday() - philo->last_eat;
        if (timestamp >= philo->data->time_to_die && philo->data->finished != 1)
        {
            print_message(ft_gettimeday() - philo->data->start_time, philo, "has died");
            philo->data->finished = 1;
            return (1);
        }
    }
    return (0);
}

void    *check_end_simulation(void *data)
{
    t_data *sim;

    sim = data;
    while (sim->finished != 1)
    {
        if (sim->number_eat == sim->must_eat_number)
        {
            sim->finished = 1;
        }
    }
    return (NULL);
}
