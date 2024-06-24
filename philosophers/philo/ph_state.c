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

t_ph_state	check_state(t_philo *philo)
{
	if (get_philo_state(philo->state) == DEAD)
		return (DEAD);
	if (get_timestamp(philo->start_time) - philo->last_meal_time \
			>= philo->time_to_die)
	{
		set_philo_state(philo->state, DEAD);
		return (DEAD);
	}
	return (ALIVE);
}

void	set_philo_state(t_state *state, t_ph_state state_val)
{
	pthread_mutex_lock(&state->mutex);
	state->state_val = state_val;
	pthread_mutex_unlock(&state->mutex);
}

t_ph_state	get_philo_state(t_state *state)
{
	t_ph_state	state_val;

	pthread_mutex_lock(&state->mutex);
	state_val = state->state_val;
	pthread_mutex_unlock(&state->mutex);
	return (state_val);
}
