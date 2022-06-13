/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:37:09 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/13 13:34:03 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	app_error(int code)
{
	if (code == 8)
		printf("Error: Forking the process | Semaphore initilization failed\n");
	if (code == 1)
		printf("Error: Invalid Arguments\n");
	else if (code == 2)
		printf("Error: Invalid number of arguments\n");
	else if (code == 3)
		printf("Error: Invalid number of philosophers\n");
	else if (code == 4)
		printf("Error: Invalid time to die\n");
	else if (code == 5)
		printf("Error: Invalid time to sleep\n");
	else if (code == 6)
		printf("Error: Invalid time to eat\n");
	else if (code == 7)
		printf("Error: Invalid numbers of time that a philosopher should eat\n");
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
	long	starttime;

	starttime = ft_gettimeday();
	while ((ft_gettimeday() - starttime) < time)
		usleep(50);
}

long long	ft_gettimeday(void)
{
	struct timeval	ms;

	gettimeofday(&ms, NULL);
	return (ms.tv_usec / 1000 + ms.tv_sec * 1000);
}

void	print_message(long time, t_philo *philo, char *state)
{
	sem_wait(philo->data->print);
	printf("%ld %d %s\n", time, philo->id, state);
	if (ft_strcmp(state, "died") != 0)
		sem_post(philo->data->print);
}
