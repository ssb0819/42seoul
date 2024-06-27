/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:10:53 by subson            #+#    #+#             */
/*   Updated: 2024/06/27 13:08:18 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ph_action(void *arg);
static int	ph_eat(t_philo *philo);
static int	ph_sleep(t_philo *philo);
static void	ph_think(t_philo *philo, int eat_cnt);

void	simulate(t_philos_info *ph_info)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * ph_info->ph_cnt);
	if (!threads)
		return ;
	i = 0;
	while (i < ph_info->ph_cnt)
	{
		// ph_info->philos[i]->start_time = get_timestamp(0);
		pthread_create(&threads[i], (void *)0, ph_action, \
						(void *)(ph_info->philos[i]));
		i++;
	}
	init_start_time(ph_info->philos, ph_info->ph_cnt);
	set_dead_flag(ph_info->philos[0], ALIVE);
	i = 0;
	while (i < ph_info->ph_cnt)
		pthread_join(threads[i++], (void *)0);
	free(threads);
}

static void	*ph_action(void *arg)
{
	t_philo		*philo;
	int			eat_cnt;

	philo = (t_philo *)arg;
	eat_cnt = 0;
	while (1)
	{
		if (get_dead_flag(philo->dead_flag) == ALIVE)
			break ;
		usleep(500);
	}
	philo->last_meal_time = philo->start_time;
	while (1)
	{
		ph_think(philo, eat_cnt);
		// print_debug(philo, "start eat function");
		if (ph_eat(philo) == DEAD)
			return ((void *)0);
		if (++eat_cnt == philo->eat_limit)
			return ((void *)0);
		// print_debug(philo, "end eat function");
		if (ph_sleep(philo) == DEAD)
			return ((void *)0);
	}
}

static void	ph_think(t_philo *philo, int eat_cnt)
{
	print_state(philo, "is thinking");
	if (eat_cnt == 0 && philo->philo_num % 2 == 0)
		usleep(philo->time_to_eat * 1000 / 2);
}

static int	ph_eat(t_philo *philo)
{
	long	start;
	int		flag;

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

static int	ph_sleep(t_philo *philo)
{
	long	start;
	long	time_passed;

	start = print_state(philo, "is sleeping");
	while (1)
	{
		if (check_dead(philo) == DEAD)
			return (DEAD);
		time_passed = get_timestamp(philo->start_time) - start;
		if (get_timestamp(philo->start_time) - start >= philo->time_to_sleep)
			return (ALIVE);
		usleep(500);
	}
}
