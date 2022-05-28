/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:35:44 by ochoumou          #+#    #+#             */
/*   Updated: 2022/05/28 11:46:01 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	char	*ms;
	char	*ms2;

	ms = "is eating";
	ms2 = "has taken a fork";
	pthread_mutex_lock(philo->left_hand);
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms2);
	pthread_mutex_lock(philo->right_hand);
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms2);
	philo->last_eat = ft_gettimeday();
	philo->eat_number += 1;
	print_message((ft_gettimeday() - philo->data->start_time), philo, ms);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
}

void	thinking(t_philo *philo)
{
	char	*ms;

	ms = "is thinking";
	if (philo->data->finished != 1)
		print_message(ft_gettimeday() - philo->data->start_time, philo, ms);
}

void	sleeping(t_philo *philo)
{
	char	*ms;

	ms = "is sleeping";
	print_message(ft_gettimeday() - philo->data->start_time, philo, ms);
	ft_sleep(philo->data->time_to_sleep);
}

void	*philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_sleep(50);
	while (philo->data->finished != 1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
