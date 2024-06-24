/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:40:01 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 18:19:04 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_start_time(t_philo **philos, int cnt)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_timestamp(0);
	while (i < cnt)
		philos[i++]->start_time = start_time;
}

int	init_state_mutex(t_state **state, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (pthread_mutex_init(&(state[i]->mutex), (void *)0) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_fork_mutex(t_fork **forks, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (pthread_mutex_init(&(forks[i]->mutex), (void *)0) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	free_all_philos(t_philos_info *ph_info)
{
	int	i;

	if (!ph_info->philos)
		return ;
	i = 0;
	while (i < ph_info->ph_cnt)
	{
		if (i == 0)
		{
			pthread_mutex_destroy(ph_info->philos[i]->std_mutex);
			free(ph_info->philos[i]->std_mutex);
		}
		pthread_mutex_destroy(&ph_info->philos[i]->left->mutex);
		free(ph_info->philos[i]->left);
		pthread_mutex_destroy(&ph_info->philos[i]->state->mutex);
		free(ph_info->philos[i]->state);
		i++;
	}
	free(ph_info->philos);
}
