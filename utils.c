#include "philosophers.h"

void    app_error(int code)
{
    if (code == 1)
		printf("Error: Invalid Arguments\n");
	else if (code == 2)
		printf("Error: Invalid number of arguments\n");
    exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_sleep(long time)
{
	long starttime;

	starttime = ft_gettimeday();
	
	while ((ft_gettimeday() - starttime) < time)
		usleep(50);
}

//? This function will return time in miliseconds.
long ft_gettimeday(void)
{
	struct timeval ms;
	return (ms.tv_usec / 1000 + ms.tv_sec * 1000);
}

void    print_message(int time, t_philo *philo, char *state)
{
    printf("%d %d is %s\n",time, philo->id, state);
}