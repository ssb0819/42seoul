/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:46 by subson            #+#    #+#             */
/*   Updated: 2024/06/29 06:23:15 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_dead_msg(t_philo *philo)
{
	pthread_mutex_lock(philo->std_mutex);
	printf("%ld %d %s\n", get_timestamp(philo->start_time), \
			philo->philo_num, "died");
	pthread_mutex_unlock(philo->std_mutex);
}

long	print_state(t_philo *philo, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(philo->std_mutex);
	timestamp = get_timestamp(philo->start_time);
	if (get_ph_state(philo->ph_state) != DEAD)
		printf("%ld %d %s\n", timestamp, philo->philo_num, msg);
	pthread_mutex_unlock(philo->std_mutex);
	return (timestamp);
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
