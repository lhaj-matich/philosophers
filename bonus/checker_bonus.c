/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:32:30 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/11 13:44:42 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo_dies(t_philo *philo)
{
	long long	timestamp;

	timestamp = ft_gettimeday() - philo->last_eat;
	if (timestamp > philo->data->time_to_die)
	{
		print_message(ft_gettimeday() - philo->data->start_time, philo, "died");
		return (1);
	}
	return (0);
}

int	check_end_simulation(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->eat_number >= philo->data->must_eat_number + 1)
		return (1);
	return (0);
}
