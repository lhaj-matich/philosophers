#include "philosophers.h"

t_data *init_data()
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->state = 1; // This means that the simulation is working fine. when turned to 0 means that the simulation should stop.
    return (data);
}

int main(int argc,char **argv)
{
    
    if (argc >= 5)
    {
        t_data *data;
        data = init_data();
        parse_args(argc, argv, data);
        start_sim(data);
    }
    else
        app_error(2);
    return (0);
}