#include "philosophers.h"

void    eating(t_philo *philo)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    philo->last_eat = now;
    // Philosopher is getting the forks.
    pthread_mutex_lock(&philo->left_hand);
    print_message(now, &philo , "Picked up the left fork");
    pthread_mutex_lock(&philo->right_hand);
    print_message(now, &philo , "Picked up the right fork");
    usleep(philo->data->time_to_sleep);
    pthread_mutex_lock(&philo->left_hand);
    print_message(now, &philo , "Put down the left fork");
    pthread_mutex_lock(&philo->right_hand);
    print_message(now, &philo , "Put down the right fork");
}

void    thinking(t_philo *philo)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    print_message(now, &philo ,"is thinking");
}

void    sleeping(t_philo *philo)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    print_message(now, &philo, "is sleeping");
    usleep(philo->data->time_to_sleep);
}

void    *philo(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (philo->id % 2 == 0)
        usleep(500);
    while (philo->data->finished != 1)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
}