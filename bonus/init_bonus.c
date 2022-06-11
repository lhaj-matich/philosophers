/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:34:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/09 11:27:48 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_semaphore(t_data *data)
{
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
	data->print = sem_open(PRINT_SEM, O_CREAT | O_EXCL, 0644, 1);
	data->forks = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 0644, \
	data->philos_number);
	if (data->print == SEM_FAILED || data->forks == SEM_FAILED)
		app_error(8);
}

void	create_philos(t_data *data)
{
	int	j;

	j = 0;
	init_semaphore(data);
	data->start_time = ft_gettimeday();
	data->philos = malloc(sizeof(t_philo) * data->philos_number);
	while (j < data->philos_number)
	{
		data->philos[j].id = j + 1;
		data->philos[j].eat_number = 0;
		data->philos[j].last_eat = data->start_time;
		data->philos[j].data = data;
		data->philos[j].pid = fork();
		if (data->philos[j].pid == -1)
			app_error(8);
		else if (data->philos[j].pid == 0)
		{
			pthread_create(&data->philos[j].thread, NULL, \
			check_philo_dead, &data->philos[j]);
			philo(&data->philos[j]);
		}
		j += 1;
	}
}

void	*check_philo_dead(void *args)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = args;
	while (1)
	{
		if (check_philo_dies(philo))
			exit(1);
	}
	return (NULL);
}
