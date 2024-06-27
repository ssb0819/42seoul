/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:35:42 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 15:47:49 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_philo *philo)
{
	if (get_dead_flag(philo->dead_flag) == DEAD)
		return (DEAD);
	if (get_timestamp(philo->start_time) - philo->last_meal_time \
			>= philo->time_to_die)
	{
		set_dead_flag(philo, DEAD);
		return (DEAD);
	}
	return (ALIVE);
}

void	set_dead_flag(t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->dead_flag->mutex);
	if (flag == DEAD && philo->dead_flag->flag != DEAD)
	{
		print_dead_msg(philo);
		philo->dead_flag->flag = DEAD;
	}
	else if (flag == ALIVE)
		philo->dead_flag->flag = ALIVE;
	pthread_mutex_unlock(&philo->dead_flag->mutex);
}

int	get_dead_flag(t_dead_flag *dead_flag)
{
	int	flag;

	pthread_mutex_lock(&dead_flag->mutex);
	flag = dead_flag->flag;
	pthread_mutex_unlock(&dead_flag->mutex);
	return (flag);
}
