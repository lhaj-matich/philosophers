#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h> // For using the usleep function


//? This struct will contain simulation data.
typedef struct s_data 
{
    struct s_philo *philos;
    int philos_number;
    int number_eat;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_number; //? This is the number of times that each philosopher must eat.
    int finished; //? This variable controls weather the simulation is over or not.
    long long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t finshed_state;
} t_data;

//? This struct will contain philosopher data.
typedef struct s_philo 
{
    int id; 
    long long   last_eat;
    int eat_number;
    pthread_t thread;
    pthread_mutex_t *right_hand;
    pthread_mutex_t *left_hand;
    t_data *data;
} t_philo;


//* Parsing functions:
void    parse_args(int argc, char **argv, t_data *data);
void    *philo(void *data);
//* Helper functions:
void    app_error(int code);
int     ft_atoi(const char *str);
void    print_message(int time, t_philo *philo, char *state);
long long    ft_gettimeday(void);
void	ft_sleep(long time);
int     check_philo_dies(t_philo *philo);
int     check_end_simulation(t_data *data);
//* Checker functions:
void    create_philos(t_data *data);
void    start_sim(t_data *data);

#endif