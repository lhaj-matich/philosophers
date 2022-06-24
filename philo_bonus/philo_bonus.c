/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:35:44 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/11 13:44:13 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	char	*ms;
	char	*ms2;

	ms = "is eating";
	ms2 = "has taken a fork";
	sem_wait(philo->data->forks);
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms2);
	sem_wait(philo->data->forks);
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms2);
	philo->last_eat = ft_gettimeday();
	philo->eat_number += 1;
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms);
	ft_sleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	thinking(t_philo *philo)
{
	char	*ms;

	ms = "is thinking";
	print_message(ft_gettimeday() - philo->data->start_time, philo, ms);
}

void	sleeping(t_philo *philo)
{
	char	*ms;

	ms = "is sleeping";
	print_message(ft_gettimeday() - philo->data->start_time, philo, ms);
	ft_sleep(philo->data->time_to_sleep);
}

void	philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(50);
	while (1)
	{
		if (philo->data->must_eat_number != -1 && check_end_simulation(philo))
			exit(0);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
