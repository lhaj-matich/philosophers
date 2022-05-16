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
	long wait;
	struct timeval now;
	struct timeval req;

	gettimeofday(&now, NULL);

	while (wait < time)
	{
		wait = (req.tv_usec - now.tv_usec) / 1000;
		usleep(50);
	}
}

long	ft_convert_ms(struct timeval timestamp)
{
	return (timestamp.tv_usec / 1000);
}

void    print_message(struct timeval timestamp, t_philo *philo, char *state)
{
    printf("%ld %d is %s\n",ft_convert_ms(timestamp), philo->id, state);
}