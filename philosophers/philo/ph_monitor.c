/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:23 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 18:05:01 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void			*monitor(void *arg);
static t_ph_state	check_dead(t_philos_info *ph_info, int ph_idx);
static void			set_all_dead(t_philo **philos, int ph_cnt);

int	start_monitoring(t_philos_info *philos_info)
{
	pthread_t		*thread;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		return (0);
	pthread_create(thread, (void *)0, monitor, (void *)philos_info);
	pthread_detach(*thread);
	free(thread);
	return (1);
}

static void	*monitor(void *arg)
{
	t_philos_info	*ph_info;
	t_ph_state		ph_state;
	int				i;
	int				end_cnt;

	ph_info = (t_philos_info *)arg;
	while (1)
	{
		i = 0;
		end_cnt = 0;
		while (i < ph_info->ph_cnt)
		{
			ph_state = check_dead(ph_info, i);
			if (ph_state == DEAD)
				return ((void *)0);
			else if (ph_state == END)
				end_cnt++;
			i++;
		}
		if (end_cnt == ph_info->ph_cnt)
			return ((void *)0);
		usleep(500);
	}
}

static t_ph_state	check_dead(t_philos_info *ph_info, int ph_idx)
{
	t_ph_state		ph_state;

	ph_state = get_philo_state(ph_info->philos[ph_idx]->state);
	if (ph_state == DEAD)
	{
		print_dead_state(ph_info->philos[ph_idx]);
		set_all_dead(ph_info->philos, ph_info->ph_cnt);
	}
	return (ph_state);
}

static void	set_all_dead(t_philo **philos, int ph_cnt)
{
	int	i;

	i = 0;
	while (i < ph_cnt)
		set_philo_state(philos[i++]->state, DEAD);
}
