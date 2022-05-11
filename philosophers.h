#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h> // For using the usleep function

#define THINKING 1
#define EATING 2

//? This struct will contain simulation data.
typedef struct s_data 
{
    struct s_philo *philos;
    int philos_number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_number; //? This is the number of times that each philosopher must eat.
    int state; //? This variable controls weather the simulation is over or not.
    pthread_mutex_t *forks;
    pthread_mutex_t set_state;
} t_data;

//? This struct will contain philosopher data.
typedef struct s_philo 
{
    struct timeval last_eat;
    int id;
    int number_eat; //? This number is the number of times a philosopher has eaten.
    int state;
    pthread_t thread;
    pthread_mutex_t right_hand;
    pthread_mutex_t left_hand;
    t_data *data;
} t_philo;

//* Parsing functions:
void    parse_args(int argc, char **argv, t_data *data);
void    *philo(void *data);
//* Helper functions:
void    app_error(int code);
int     ft_atoi(const char *str);
long	ft_convert_ms(struct timeval timestamp);
void    print_message(struct timeval timestamp, t_philo *philo, char *state);
//* Checker functions:
void    create_philos(t_data *data);
void    start_sim(t_data *data);
#endif