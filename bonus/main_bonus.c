/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:22:19 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/13 13:38:50 by ochoumou         ###   ########.fr       */
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

void	ft_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
}

void	process_exit(t_data *data, int status, int n)
{
	if (n == 0)
		return ;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (process_exit(data, status, n - 1));
		else
			ft_kill(data);
	}
}

int	main(int argc, char **argv)
{
	int		status;
	t_data	*data;

	status = 0;
	if (argc >= 5)
	{
		data = init_data();
		parse_args(argc, argv, data);
		create_philos(data);
		process_exit(data, status, data->philos_number);
		end_simulation(data);
	}
	else
		app_error(2);
	return (0);
}
