/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:10:53 by subson            #+#    #+#             */
/*   Updated: 2024/07/08 22:03:08 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_ph_state	ph_eat(t_philo *philo);
static t_ph_state	ph_sleep(t_philo *philo);
static void			ph_think(t_philo *philo);

void	*ph_action(t_philo *philo)
{
	int			eat_cnt;

	eat_cnt = 0;
	while (philo->eat_limit != 0)
	{
		ph_think(philo);
		if (ph_eat(philo) == DEAD)
			return ((void *)0);
		if (++eat_cnt == philo->eat_limit)
			exit(EXIT_SUCCESS);
		if (ph_sleep(philo) == DEAD)
			return ((void *)0);
	}
}

static void	ph_think(t_philo *philo)
{
	print_state(philo, "is thinking");
	usleep(900);
}

static t_ph_state	ph_eat(t_philo *philo)
{
	long		start;
	t_ph_state	flag;

	if (take_forks(philo) == DEAD)
		return (DEAD);
	start = print_state(philo, "is eating");
	philo->last_meal_time = start;
	while (1)
	{
		if (check_dead(philo) == DEAD)
		{
			flag = DEAD;
			break ;
		}
		if (get_timestamp(philo->start_time) - start \
				>= (long)philo->time_to_eat)
		{
			flag = ALIVE;
			break ;
		}
		usleep(500);
	}
	return_forks(philo);
	return (flag);
}

static t_ph_state	ph_sleep(t_philo *philo)
{
	long	start;
	long	time_passed;

	start = print_state(philo, "is sleeping");
	while (1)
	{
		if (check_dead(philo) == DEAD)
			return (DEAD);
		time_passed = get_timestamp(philo->start_time) - start;
		if (time_passed >= philo->time_to_sleep)
			return (ALIVE);
		usleep(500);
	}
}
