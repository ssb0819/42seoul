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

#include "philo_bonus.h"

int	check_dead(t_philo *philo)
{
	if (get_d_flag(&philo->death_flag) == DEAD)
		return (DEAD);
	if (get_timestamp(philo->start_time) - philo->last_meal_time \
			>= philo->time_to_die)
	{
		set_d_flag(&philo->death_flag, DEAD);
		return (DEAD);
	}
	return (ALIVE);
}

void	set_d_flag(t_death_flag *d_flag, int flag)
{
	sem_wait(d_flag->sem);
	d_flag->flag = flag;
	sem_post(d_flag->sem);
}

int	get_d_flag(t_death_flag *d_flag)
{
	int	flag;

	sem_wait(d_flag->sem);
	flag = d_flag->flag;
	sem_post(d_flag->sem);
	return (flag);
}
