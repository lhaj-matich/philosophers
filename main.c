/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:22:19 by ochoumou          #+#    #+#             */
/*   Updated: 2022/05/28 11:28:19 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->finished = 0;
	data->must_eat_number = -1;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc >= 5)
	{
		data = init_data();
		parse_args(argc, argv, data);
		create_philos(data);
		start_sim(data);
	}
	else
		app_error(2);
	return (0);
}
