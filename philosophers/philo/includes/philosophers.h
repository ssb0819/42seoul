/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/06/25 19:11:05 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define DEAD 0
# define ALIVE 1

typedef enum e_resource_state
{
	AVAILABLE,
	IN_USE
}			t_r_state;

typedef struct s_dead_flag
{
	int				flag;
	pthread_mutex_t	mutex;
}				t_dead_flag;

typedef struct s_fork
{
	t_r_state		state;
	int				waiting_ph;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int				philo_num;
	t_dead_flag		*dead_flag;
	t_fork			*left;
	t_fork			*right;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_limit;
	long			start_time;
	long			last_meal_time;
	pthread_mutex_t	*std_mutex;
}				t_philo;

typedef struct s_philos_info
{
	t_philo	**philos;
	int		ph_cnt;
}				t_philos_info;


/* main function */
int		philo_init(t_philos_info *ph_info, char **argv);
void	simulate(t_philos_info *ph_info);

/* fork */
int		take_forks(t_philo *philo);
void	return_forks(t_philo *philo);

/* dead_flag */
int		check_dead(t_philo *philo);
void	set_dead_flag(t_philo *philo, int flag);
int		get_dead_flag(t_dead_flag *dead_flag);

/* init utils */
void	init_start_time(t_philo **philos, int cnt);
int		init_fork_mutex(t_fork **forks, int cnt);
void	free_all_philos(t_philos_info *ph_info);

/* print */
void	print_dead_msg(t_philo *philo);
long	print_state(t_philo *philo, char *msg);
int		print_err(char *err_msg);
long	get_timestamp(long start_time);

/* utils */
int		ph_atoi(const char *str);
void	**make_array(size_t size, int cnt);
void	free_array(void **arr, int cnt);

/* debug */
void	check_fork_init(t_philo **philos, int ph_cnt);
void	print_debug(t_philo *philo, char *msg);

#endif