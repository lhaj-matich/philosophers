#include "philosophers.h"

//!Error Handling:
//!Check that the number of args correspond to 
//!Don't forget to change the system function with our own function.

void    parse_args(int argc, char **argv, t_data *data)
{
    if (argc > 1)
    {
        data->time_to_sleep = ft_atoi(argv[4]);
        data->time_to_die = ft_atoi(argv[2]);
        data->time_to_eat = ft_atoi(argv[3]);
        data->philos_number = ft_atoi(argv[1]);
    }
    else if (argc == 6)
        data->must_eat_number = ft_atoi(argv[5]);
    else
        app_error(2);
}