#include "philosophers.h"

int check_philo_dies(t_philo *philo)
{
    long long timestamp;

    timestamp = ft_gettimeday() - philo->last_eat;
    // printf("Philo: %d Time left: %lld Time to die: %d\n", philo->id ,timestamp, philo->data->time_to_die);
    if (timestamp > philo->data->time_to_die && philo->data->finished != 1)
    {
        print_message(ft_gettimeday() - philo->data->start_time, philo, "has died");
        philo->data->finished = 1;
        return (1);
    }
    return (0);
}

int check_end_simulation(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philos_number)
    {
        if (data->philos[i].eat_number >= data->must_eat_number)
            i++;
        else
            return (0);
    }
    data->finished = 1;
    return (1);
}
