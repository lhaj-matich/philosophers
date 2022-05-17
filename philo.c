#include "philosophers.h"

void    *check_philo_died(t_philo *philo)
{
    long now;
    long ms;

    ms = philo->last_eat - ft_gettimeday();
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_hand);
    print_message((philo->data->start_time - ft_gettimeday()), &philo , "has taken a fork");
    pthread_mutex_lock(&philo->right_hand);
    print_message((philo->data->start_time - ft_gettimeday()), &philo , "has taken a fork");
    ft_sleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->left_hand);
    pthread_mutex_unlock(&philo->right_hand);
    philo->last_eat = ft_gettimeday();
}

void    thinking(t_philo *philo)
{
    print_message(ft_gettimeday(), &philo ,"is thinking");
}

void    sleeping(t_philo *philo)
{
    print_message(ft_gettimeday(), &philo, "is sleeping");
    ft_sleep(philo->data->time_to_sleep);
}

void    *philo(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (philo->id % 2 == 0)
        ft_usleep(50);
    while (philo->data->finished != 1)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
}