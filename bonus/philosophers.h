/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:38:05 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/08 14:03:03 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>

# define FORKS_SEM "PHILO_FORKS"
# define PRINT_SEM "PHILO_PRINT"

typedef struct s_data
{
	struct s_philo	*philos;
	int				philos_number;
	int				number_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_number;
	int				finished;
	long long		start_time;
	sem_t			*forks;
	sem_t			*print;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				pid;
	int				eat_number;
	long long		last_eat;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

void		philo(t_philo *philo);
void		parse_args(int argc, char **argv, t_data *data);
void		print_message(long time, t_philo *philo, char *state);
void		app_error(int code);
int			ft_atoi(const char *str);
int			check_philo_dies(t_philo *philo);
int			check_end_simulation(t_data *data);
long long	ft_gettimeday(void);
void		ft_sleep(long time);
void		create_philos(t_data *data);
void		start_sim(t_data *data);

#endif