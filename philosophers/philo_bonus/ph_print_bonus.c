/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:46 by subson            #+#    #+#             */
/*   Updated: 2024/07/05 22:08:48 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_dead_msg(t_philo *philo)
{
	sem_wait(philo->print_sem);
	printf("%ld %d %s\n", get_timestamp(philo->start_time), \
			philo->philo_num, "died");
	sem_post(philo->print_sem);
}

long	print_state(t_philo *philo, char *msg)
{
	long	timestamp;

	sem_wait(philo->print_sem);
	timestamp = get_timestamp(philo->start_time);
	if (get_d_flag(&philo->death_flag) != DEAD)
		printf("%ld %d %s\n", timestamp, philo->philo_num, msg);
	sem_post(philo->print_sem);
	return (timestamp);
}

int	print_err_and_exit(char *err_msg)
{
	printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

long	get_timestamp(long start_time)
{
	long			cur;
	struct timeval	tv;

	gettimeofday(&tv, (void *)0);
	cur = (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (cur - start_time);
}
