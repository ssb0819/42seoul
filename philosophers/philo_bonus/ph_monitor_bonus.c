/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:10:09 by subson            #+#    #+#             */
/*   Updated: 2024/07/05 22:16:14 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*monitor(void *arg);

void	start_monitoring(t_philo *philo)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		print_err_and_exit("Error: Memory Error\n");
	pthread_create(thread, (void *)0, monitor, (void *)philo);
	pthread_detach(*thread);
	free(thread);
}

static void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_d_flag(&philo->death_flag) == DEAD)
			close_sems_amd_exit(philo);
		if (get_timestamp(philo->start_time) - philo->last_meal_time \
				>= philo->time_to_die)
		{
			set_d_flag(&philo->death_flag, DEAD);
			print_dead_msg(philo);
			close_sems_amd_exit(philo);
		}
		usleep(500);
	}
}
