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

t_ph_state	check_dead(t_philo *philo)
{
	if (get_ph_state(philo->ph_state) == DEAD)
		return (DEAD);
	if (get_timestamp(philo->start_time) - philo->last_meal_time \
			>= philo->time_to_die)
	{
		set_ph_state(philo->ph_state, DEAD);
		return (DEAD);
	}
	return (ALIVE);
}

void	set_ph_state(t_state *ph_state, t_ph_state state)
{
	pthread_mutex_lock(&ph_state->mutex);
		ph_state->state = state;
	pthread_mutex_unlock(&ph_state->mutex);
}

t_ph_state	get_ph_state(t_state *ph_state)
{
	t_ph_state	state;

	pthread_mutex_lock(&ph_state->mutex);
	state = ph_state->state;
	pthread_mutex_unlock(&ph_state->mutex);
	return (state);
}
