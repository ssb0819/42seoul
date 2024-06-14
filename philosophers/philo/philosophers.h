/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/06/14 19:47:49 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_last_meal
{
	unsigned int	*time;
	pthread_mutex_t	mutex;
}				t_last_meal;


typedef struct s_philo
{
	pthread_t		thread_t;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	unsigned int	eat_limit;
	t_last_meal		*last_meal;
}				t_philo;

/* utils */
void	ft_putstr_fd(char *s, int fd);
int		ph_atoi(const char *str);

#endif