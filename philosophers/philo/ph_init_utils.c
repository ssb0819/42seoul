/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:40:01 by subson            #+#    #+#             */
/*   Updated: 2024/07/03 09:47:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	set_etc(t_philo **philos, int cnt, char *eat_limit_str)
{
	int		i;
	int		eat_limit;

	i = 0;
	eat_limit = 0;
	if (eat_limit_str)
		eat_limit = ph_atoi(eat_limit_str);
	if (eat_limit < 0)
		return (0);
	while (i < cnt)
	{
		philos[i]->philo_num = i + 1;
		if (eat_limit > 0)
			philos[i]->eat_limit = eat_limit;
		else
			philos[i]->eat_limit = 0;
		i++;
	}
	return (1);
}

void	init_start_time(t_philo **philos, int cnt)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_timestamp(0);
	while (i < cnt)
	{
		philos[i]->start_time = start_time;
		i++;
	}
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

int	init_state_mutex(t_state **states, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (pthread_mutex_init(&(states[i]->mutex), (void *)0) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	clean_all_philos(t_philos_info *ph_info)
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
		pthread_mutex_destroy(&ph_info->philos[i]->ph_state->mutex);
		free(ph_info->philos[i]->ph_state);
		i++;
	}
	free(ph_info->philos);
}
