/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:21:59 by subson            #+#    #+#             */
/*   Updated: 2024/07/10 08:45:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_ph_state	get_a_fork(t_fork *fork, t_philo *philo);
static void			return_a_fork(t_fork *fork);

t_ph_state	get_forks(t_philo *philo)
{
	if (philo->philo_num % 2 == 1)
	{
		if (get_a_fork(philo->left, philo) == DEAD)
			return (DEAD);
		if (get_a_fork(philo->right, philo) == DEAD)
			return (DEAD);
	}
	else
	{
		if (get_a_fork(philo->right, philo) == DEAD)
			return (DEAD);
		if (get_a_fork(philo->left, philo) == DEAD)
			return (DEAD);
	}
	return (ALIVE);
}

static t_ph_state	get_a_fork(t_fork *fork, t_philo *philo)
{
	while (1)
	{
		if (check_dead(philo) == DEAD)
			return (DEAD);
		pthread_mutex_lock(&fork->mutex);
		if (fork->state == AVAILABLE)
		{
			fork->state = IN_USE;
			pthread_mutex_unlock(&fork->mutex);
			print_state(philo, "has taken a fork");
			return (ALIVE);
		}
		pthread_mutex_unlock(&fork->mutex);
		usleep(400);
	}
}

void	put_forks(t_philo *philo)

{
	if (philo->philo_num % 2 == 1)
	{
		return_a_fork(philo->left);
		return_a_fork(philo->right);
	}
	else
	{
		return_a_fork(philo->right);
		return_a_fork(philo->left);
	}
}

static void	return_a_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->state = AVAILABLE;
	pthread_mutex_unlock(&fork->mutex);
}
