/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:34:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/08 14:03:50 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->check, NULL);
	while (i < data->philos_number)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i += 1;
	}
}

void	create_philos(t_data *data)
{
	int	j;

	j = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
	data->philos = malloc(sizeof(t_philo) * data->philos_number);
	data->start_time = ft_gettimeday();
	init_forks(data);
	while (j < data->philos_number)
	{
		data->philos[j].id = j + 1;
		data->philos[j].eat_number = 0;
		data->philos[j].last_eat = data->start_time;
		data->philos[j].left_hand = &data->forks[j];
		if (data->philos[j].id != data->philos_number)
			data->philos[j].right_hand = &data->forks[j + 1];
		else
		{
			data->philos[j].right_hand = &data->forks[(j + 1) % \
			data->philos_number];
		}
		data->philos[j].data = data;
		j += 1;
	}
}

void	check_philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		if (check_philo_dies(&data->philos[i]))
			break ;
		i += 1;
		if (i == data->philos_number)
		{
			if (data->must_eat_number != -1 && check_end_simulation(data))
				return ;
			i = 0;
		}
	}
}

void	start_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		pthread_create(&data->philos[i].thread, NULL, philo, &data->philos[i]);
		pthread_detach(data->philos[i].thread);
		i += 1;
	}
	check_philo_dead(data);
}
