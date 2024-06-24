/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:46 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 17:04:45 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_and_print_state(long timestamp, t_philo *philo, char *msg)
{
	if (check_state(philo) == DEAD)
		return ;
	print_state(timestamp, philo->philo_num, philo->std_mutex, msg);
}

void	print_dead_state(t_philo *philo)
{
	print_state(get_timestamp(philo->start_time), philo->philo_num, \
								philo->std_mutex, "died");
}

void	print_state(long timestamp, int ph_n, pthread_mutex_t *mutex, char *msg)
{
	pthread_mutex_lock(mutex);
	printf("%ld %d %s\n", timestamp, ph_n, msg);
	pthread_mutex_unlock(mutex);
}

int	print_err(char *err_msg)
{
	printf("%s", err_msg);
	return (0);
}

long	get_timestamp(long start_time)
{
	long			cur;
	struct timeval	tv;

	gettimeofday(&tv, (void *)0);
	cur = (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (cur - start_time);
}
