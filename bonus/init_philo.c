/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:34:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/08 13:58:21 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_semaphore(t_data *data)
{
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);

	data->print = sem_open(PRINT_SEM, O_CREAT | O_EXCL, 0644, 1);
	data->forks = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 0644 , data->philos_number);
	if (data->print == SEM_FAILED || data->forks == SEM_FAILED)
		app_error(8);
}

void	create_philos(t_data *data)
{
	int	j;

	j = 0;
	data->philos = malloc(sizeof(t_philo) * data->philos_number);
	data->start_time = ft_gettimeday();
	init_semaphore(data);
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
			pthread_create(data->philos[j].thread, NULL, check_philo_dead, data);
			pthread_detach(data->philos[j].thread);
		}
		j += 1;
	}
	// Here i should listen if a process exited with other status than 0 so i could kill all the processes.
}

void	*check_philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		if (check_philo_dies(&data->philos[i]))
			exit(1); // Later i should listen on this status code to see which process has exited
		i += 1;
		if (i == data->philos_number)
		{
			if (data->must_eat_number != -1 && check_end_simulation(data))
				exit(0);
			i = 0;
		}
	}
	return (NULL);
}
