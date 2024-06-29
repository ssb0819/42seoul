/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:10:53 by subson            #+#    #+#             */
/*   Updated: 2024/06/29 07:37:57 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void			*ph_action(void *arg);
static t_ph_state	ph_eat(t_philo *philo);
static t_ph_state	ph_sleep(t_philo *philo);
static void			ph_think(t_philo *philo, int eat_cnt);

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
		if (i % 2 == 0)
			pthread_create(&threads[i], (void *)0, ph_action, \
							(void *)(ph_info->philos[i]));
		i++;
	}
	i = 0;
	while (i < ph_info->ph_cnt)
	{
		// ph_info->philos[i]->start_time = get_timestamp(0);
		if (i % 2 == 1)
			pthread_create(&threads[i], (void *)0, ph_action, \
							(void *)(ph_info->philos[i]));
		i++;
	}
	init_start_time(ph_info->philos, ph_info->ph_cnt);
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
	while (1) // 삭제?
	{
		if (get_ph_state(philo->ph_state) == ALIVE)
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
		{
			set_ph_state(philo->ph_state, END);
			return ((void *)0);
		}
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
		usleep(50);
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
