#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For using the usleep function


// This struct will contain simulation data.
typedef struct data 
{
    int philos_number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_number; // This is the number of times that each philosopher must eat.
} t_data;

#endif