#include "philosophers.h"


void    *check_philo_dies(void *data)
{
    t_philo *philo;
    long timestamp;

    philo = data;
    while (philo->data->finished != 1)
    {
        pthread_mutex_lock(&philo->data->finshed_state);
        timestamp = ft_gettimeday() - philo->last_eat;
        if (timestamp > philo->data->time_to_die && philo->data->finished != 1)
        {
            print_message(ft_gettimeday() - philo->data->start_time, philo, "has died");
            philo->data->finished = 1;
        }
        /// We are not sure that this is the right place for the mutex to be.
        /// I will run the code and see if there is some optimizations that could be done.
        pthread_mutex_unlock(&philo->data->finshed_state);
    }
    return (NULL);
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
