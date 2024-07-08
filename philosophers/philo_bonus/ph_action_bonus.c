/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:10:53 by subson            #+#    #+#             */
/*   Updated: 2024/07/08 22:02:50 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ph_eat(t_philo *philo);
static void	ph_sleep(t_philo *philo);
static void	ph_think(t_philo *philo);

void	ph_action(t_philo *philo)
{
	int			eat_cnt;

	start_monitoring(philo);
	eat_cnt = 0;
	while (philo->eat_limit != 0)
	{
		ph_think(philo);
		ph_eat(philo);
		if (++eat_cnt == philo->eat_limit)
			close_sems_and_exit(philo, EXIT_SUCCESS);
		ph_sleep(philo);
	}
}

static void	ph_think(t_philo *philo)
{
	print_state(philo, "is thinking");
	usleep(900);
}

static void	ph_eat(t_philo *philo)
{
	long	start;

	sem_wait(philo->forks);
	sem_wait(philo->forks);
	start = print_state(philo, "is eating");
	philo->last_meal_time = start;
	while (1)
	{
		if (get_timestamp(philo->start_time) - start \
				>= (long)philo->time_to_eat)
			break ;
		usleep(500);
	}
	sem_post(philo->forks);
	sem_post(philo->forks);
}

static void	ph_sleep(t_philo *philo)
{
	long	start;
	long	time_passed;

	start = print_state(philo, "is sleeping");
	while (1)
	{
		time_passed = get_timestamp(philo->start_time) - start;
		if (time_passed >= philo->time_to_sleep)
			return ;
		usleep(500);
	}
}
