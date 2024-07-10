/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/07/10 13:08:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <signal.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define ODD 0
# define EVEN 1

# define NO_LIMIT -1

# define FORKS_SEM "forks"
# define PRINT_SEM "print"

typedef struct s_last_meal
{
	long	time;
	sem_t	*sem;
}				t_last_meal;

typedef struct s_philo
{
	int				philo_num;
	sem_t			*forks;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_limit;
	long			start_time;
	t_last_meal		last_meal;
	sem_t			*print_sem;
}				t_philo;

/* action & monitor */
void	ph_action(t_philo *philo);
void	start_monitoring(t_philo *philo);

/* semaphore */
void	open_sems(t_philo *philo, int ph_cnt);
void	close_sems(t_philo *philo);
void	unlink_all_sems(void);

/* last_meal */
long	get_last_meal_time(t_last_meal *last_meal);
void	set_last_meal_time(t_last_meal *last_meal, long last_meal_time);
char	*make_lm_sem_name(int n);

/* print */
int		print_err_and_exit(char *err_msg);
long	get_timestamp(long start_time);
long	print_state(t_philo *philo, char *msg);

/* utils */
int		ph_atoi(const char *str);

#endif