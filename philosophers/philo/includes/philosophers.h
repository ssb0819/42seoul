/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 18:29:24 by subson           ###   ########.fr       */
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

typedef enum e_philo_state
{
	ALIVE,
	END,
	DEAD
}			t_ph_state;

typedef enum e_resource_state
{
	AVAILABLE,
	IN_USE
}			t_r_state;

typedef struct s_state
{
	t_ph_state		state_val;
	pthread_mutex_t	mutex;
}				t_state;

typedef struct s_fork
{
	t_r_state		state;
	int				waiting_ph;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int				philo_num;
	t_state			*state;
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
int			start_monitoring(t_philos_info *philos_info);

/* fork */
int			take_forks(t_philo *philo);
void		return_forks(t_philo *philo);

/* actions */
t_ph_state	ph_eat(t_philo *philo, int *eat_cnt);
t_ph_state	ph_sleep(t_philo *philo);
void		ph_think(t_philo *philo);

/* state */
t_ph_state	check_state(t_philo *philo);
void		set_philo_state(t_state *state, t_ph_state state_val);
t_ph_state	get_philo_state(t_state *state);

/* init utils */
void		init_start_time(t_philo **philos, int cnt);
int			init_state_mutex(t_state **state, int cnt);
int			init_fork_mutex(t_fork **forks, int cnt);
void		free_all_philos(t_philos_info *ph_info);

/* print */
void		check_and_print_state(long timestamp, t_philo *philo, char *msg);
void		print_dead_state(t_philo *philo);
void		print_state(long timestamp, int ph_n, pthread_mutex_t *mutex, \
						char *msg);
int			print_err(char *err_msg);
long		get_timestamp(long start_time);

/* utils */
int			ph_atoi(const char *str);
void		**make_array(size_t size, int cnt);
void		free_array(void **arr, int cnt);

/* debug */
void		check_init(t_philo **philos, t_state **statees, int ph_cnt);
void		print_debug(t_philo *philo, char *msg);

#endif