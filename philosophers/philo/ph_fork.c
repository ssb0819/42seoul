/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:21:59 by subson            #+#    #+#             */
/*   Updated: 2024/06/29 07:03:35 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_ph_state	take_a_fork(t_fork *fork, t_philo *philo);
static void			return_a_fork(t_fork *fork);

t_ph_state	take_forks(t_philo *philo)
{
	if (philo->philo_num % 2 == 1)
	{
		if (take_a_fork(philo->left, philo) == DEAD)
			return (DEAD);
		if (take_a_fork(philo->right, philo) == DEAD)
			return (DEAD);
	}
	else
	{
		if (take_a_fork(philo->right, philo) == DEAD)
			return (DEAD);
		if (take_a_fork(philo->left, philo) == DEAD)
			return (DEAD);
	}
	return (ALIVE);
}

static t_ph_state	take_a_fork(t_fork *fork, t_philo *philo)
{
	while (1)
	{
		if (check_dead(philo) == DEAD)
			return (DEAD);
		pthread_mutex_lock(&fork->mutex);
		if (fork->state == AVAILABLE && \
			(fork->waiting_ph == 0 || fork->waiting_ph == philo->philo_num))
		{
			fork->state = IN_USE;
			fork->waiting_ph = 0;
			pthread_mutex_unlock(&fork->mutex);
			print_state(philo, "has taken a fork");
			return (ALIVE);
		}
		else if (fork->state == IN_USE && fork->waiting_ph == 0)
			fork->waiting_ph = philo->philo_num;
		pthread_mutex_unlock(&fork->mutex);
		usleep(50);
	}
}

void	return_forks(t_philo *philo) // 수정 예정 - 내려놓는 순서는 상관 없을 수도
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
