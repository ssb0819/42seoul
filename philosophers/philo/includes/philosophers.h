/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/07/10 09:14:11 by root             ###   ########.fr       */
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

# define ODD 0
# define EVEN 1
# define NO_LIMIT -1

typedef enum e_fork_state
{
	AVAILABLE,
	IN_USE
}			t_f_state;

typedef enum e_philo_state
{
	ALIVE,
	DEAD,
	END
}			t_ph_state;

typedef struct s_state
{
	t_ph_state		state;
	pthread_mutex_t	mutex;
}				t_state;

typedef struct s_fork
{
	int				fork_num;
	t_f_state		state;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int				philo_num;
	t_state			*ph_state;
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
int			philo_init(t_philos_info *ph_info, char **argv);
void		simulate(t_philos_info *ph_info);
void		*ph_action(void *arg);

/* fork */
t_ph_state	get_forks(t_philo *philo);
void		put_forks(t_philo *philo);

/* state */
t_ph_state	check_dead(t_philo *philo);
void		set_ph_state(t_state *ph_state, t_ph_state flag);
t_ph_state	get_ph_state(t_state *ph_state);

/* init utils */
int			set_etc(t_philo **philos, int cnt, char *eat_limit_str);
void		init_start_time(t_philo **philos, int cnt);
int			init_fork_mutex(t_fork **forks, int cnt);
int			init_state_mutex(t_state **states, int cnt);
void		clean_all_philos(t_philos_info *ph_info);

/* print */
void		print_dead_msg(t_philo *philo);
long		print_state(t_philo *philo, char *msg);
int			print_err(char *err_msg);
long		get_timestamp(long start_time);

/* utils */
int			ph_atoi(const char *str);
void		**make_array(size_t size, int cnt);
void		free_array(void **arr, int cnt);

#endif