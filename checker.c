#include "philosophers.h"


void    *check_end_simulation(void *data)
{
    t_data *sim;

    sim = data;
    while (sim->finished != 1)
    {
        if (sim->number_eat = sim->must_eat_number)
        {
            sim->finished = 1;
        }
    }
}
