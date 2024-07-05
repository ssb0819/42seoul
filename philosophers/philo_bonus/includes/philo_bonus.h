/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/07/05 22:35:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define ODD 0
# define EVEN 1

# define DEAD 1
# define ALIVE 0

# define FORKS_SEM "forks"
# define PRINT_SEM "print"
# define D_FLAG_SEM "d_flag"

typedef struct s_death_flag
{
	int		flag;
	sem_t	*sem;
}				t_death_flag;

typedef struct s_philo
{
	int				philo_num;
	sem_t			*forks;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_limit;
	long			start_time;
	long			last_meal_time;
	sem_t			*print_sem;
	t_death_flag	death_flag;
}				t_philo;

/* action & monitor */
void	*ph_action(t_philo *philo);
void	start_monitoring(t_philo *philo);

/* semaphore */
void	open_sems(t_philo *philo, int ph_cnt);
void	close_sems_amd_exit(t_philo *philo);
void	unlink_all_sems(void);

/* print */
int		print_err_and_exit(char *err_msg);
long	get_timestamp(long start_time);
long	print_state(t_philo *philo, char *msg);
void	print_dead_msg(t_philo *philo);

/* death_flag */
void	set_d_flag(t_death_flag *d_flag, int flag);
int		get_d_flag(t_death_flag *d_flag);
int		check_dead(t_philo *philo);

/* utils */
int		ph_atoi(const char *str);

#endif