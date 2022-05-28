/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:32:30 by ochoumou          #+#    #+#             */
/*   Updated: 2022/05/28 12:40:52 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo_dies(t_philo *philo)
{
	long long	timestamp;

	timestamp = ft_gettimeday() - philo->last_eat;
	if (timestamp > philo->data->time_to_die && philo->data->finished != 1)
	{
		print_message(ft_gettimeday() - philo->data->start_time, philo, "died");
		philo->data->finished = 1;
		return (1);
	}
	return (0);
}

int	check_end_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		if (data->philos[i].eat_number >= data->must_eat_number)
			i++;
		else
			return (0);
	}
	data->finished = 1;
	return (1);
}
