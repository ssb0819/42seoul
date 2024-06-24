/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:21:06 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 18:40:07 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_ph_state	check_eating_end(t_philo *philo, long start, int *eat_cnt);

t_ph_state	ph_eat(t_philo *philo, int *eat_cnt)
{
	long		start;
	t_ph_state	state;

	if (!take_forks(philo))
		return (DEAD);
	start = get_timestamp(philo->start_time);
	check_and_print_state(start, philo, "is eating");
	philo->last_meal_time = start;
	(*eat_cnt)++;
	state = check_eating_end(philo, start, eat_cnt);
	return_forks(philo);
	return (state);
}

static t_ph_state	check_eating_end(t_philo *philo, long start, int *eat_cnt)
{
	while (1)
	{
		if (check_state(philo) == DEAD)
			return (DEAD);
		if (get_timestamp(philo->start_time) - start \
				>= (long)philo->time_to_eat)
		{
			if (*eat_cnt == philo->eat_limit)
			{
				set_philo_state(philo->state, END);
				return (END);
			}
			else
				return (ALIVE);
		}
		usleep(500);
	}
}

t_ph_state	ph_sleep(t_philo *philo)
{
	long	start;

	start = get_timestamp(philo->start_time);
	check_and_print_state(start, philo, "is sleeping");
	while (1)
	{
		if (check_state(philo) == DEAD)
			return (DEAD);
		if (get_timestamp(philo->start_time) - start >= philo->time_to_sleep)
			return (ALIVE);
		usleep(500);
	}
}

void	ph_think(t_philo *philo)
{
	check_and_print_state(get_timestamp(philo->start_time), philo, \
							"is thinking");
}
