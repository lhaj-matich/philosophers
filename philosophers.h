#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h> // For using the usleep function


typedef struct  s_timeval  {
  time_t    tv_sec ;   //used for seconds
  suseconds_t   tv_usec ;   //used for microseconds
} t_timeval;

//? This struct will contain philosopher data.
typedef struct s_philo 
{
    int number_eat; //? This number is the number of times a philosopher has eaten.
    int id;
    t_timeval last_eat;
    pthread_t thread;
    pthread_mutex_t right_hand;
    pthread_mutex_t left_hand;
} t_philo;

//? This struct will contain simulation data.
typedef struct s_data 
{
    int philos_number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_number; //? This is the number of times that each philosopher must eat.
    int state; //? This variable controls weather the simulation is over or not.
    t_philo *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t philo_died;
} t_data;

//* Parsing functions:
void    parse_args(int argc, char **argv, t_data *data);
void    philo(void *data);
//* Helper functions:
void    app_error(int code);
int     ft_atoi(const char *str);
long	ft_convert_ms(t_timeval timestamp);
void    print_message(t_timeval timestamp, t_philo *philo, char *state);
//* Checker functions:
void    create_philos(t_data *data);
#endif