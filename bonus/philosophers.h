/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:38:05 by ochoumou          #+#    #+#             */
/*   Updated: 2022/06/13 13:37:33 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <semaphore.h>

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
	int				died;
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
int			check_end_simulation(t_philo *philo);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_gettimeday(void);
void		*check_philo_dead(void *args);
void		end_simulation(t_data *data);
void		ft_sleep(long time);
void		create_philos(t_data *data);
void		start_sim(t_data *data);

#endif