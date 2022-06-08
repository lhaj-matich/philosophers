/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:22:15 by ochoumou          #+#    #+#             */
/*   Updated: 2022/05/28 12:16:56 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	validate_args(char **argv, int argc)
{
	if (argc <= 6)
	{
		if (ft_atoi(argv[1]) < 0)
			app_error(3);
		if (ft_atoi(argv[2]) < 0)
			app_error(4);
		if (ft_atoi(argv[4]) < 0)
			app_error(5);
		if (ft_atoi(argv[3]) < 0)
			app_error(6);
		if (argc == 6 && ft_atoi(argv[5]) < 0)
			app_error(7);
	}
	else
		app_error(2);
}

void	parse_args(int argc, char **argv, t_data *data)
{
	validate_args(argv, argc);
	if (argc == 6)
		data->must_eat_number = ft_atoi(argv[5]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->philos_number = ft_atoi(argv[1]);
}
