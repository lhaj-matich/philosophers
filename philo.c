#include "philosophers.h"

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_hand);
    print_message((ft_gettimeday() - philo->data->start_time), philo , "has taken a fork");
    pthread_mutex_lock(&philo->right_hand);
      print_message((ft_gettimeday() - philo->data->start_time), philo , "has taken a fork");
    if (philo->data->finished != 1)
        print_message((ft_gettimeday() - philo->data->start_time), philo , "is eating");
    philo->last_eat = ft_gettimeday();
    ft_sleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->left_hand);
    pthread_mutex_unlock(&philo->right_hand);
}

void    thinking(t_philo *philo)
{
    print_message(ft_gettimeday() - philo->data->start_time, philo ,"is thinking");
}

void    sleeping(t_philo *philo)
{
    print_message(ft_gettimeday() - philo->data->start_time, philo, "is sleeping");
    ft_sleep(philo->data->time_to_sleep);
}

void    *philo(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (philo->id % 2 == 0)
        ft_sleep(philo->data->time_to_eat / 2);
    while (philo->data->finished != 1)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}