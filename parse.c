/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:22:15 by ochoumou          #+#    #+#             */
/*   Updated: 2022/05/26 13:22:16 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	validate_args(t_data *data, int argc)
{
	if (data->philos_number < 0)
		printf("Invalid number of philosophers\n");
	if (data->time_to_die < 0)
		printf("Invalid time to die\n");
	if (data->time_to_sleep < 0)
		printf("Invalid time to sleep\n ");
	if (data->time_to_eat < 0)
		printf("Invalid time to eat\n");
	if (data->must_eat_number < 0 && argc == 6)
		printf("Invalid numbers of time that a philosopher should eat\n");
}

void	parse_args(int argc, char **argv, t_data *data)
{
	if (argc == 6)
		data->must_eat_number = ft_atoi(argv[5]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->philos_number = ft_atoi(argv[1]);
	validate_args(data, argc);
}
