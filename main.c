#include "philosophers.h"

t_data *init_data()
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->finished = 0;
    data->must_eat_number = 0;
    data->start_time = ft_gettimeday();
    return (data);
}

int main(int argc,char **argv)
{
    if (argc >= 5)
    {
        t_data *data;
        data = init_data();
        parse_args(argc, argv, data);
        create_philos(data);
        start_sim(data);
    }
    else
        app_error(2);
    return (0);
}