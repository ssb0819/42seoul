/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:10:53 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 19:09:54 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ph_action(void *arg);

void	simulate(t_philos_info *ph_info)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * ph_info->ph_cnt);
	if (!threads)
		return ;
	init_start_time(ph_info->philos, ph_info->ph_cnt);
	i = 0;
	while (i < ph_info->ph_cnt)
	{
		pthread_create(&threads[i], (void *)0, ph_action, \
						(void *)(ph_info->philos[i]));
		i++;
	}
	i = 0;
	while (i < ph_info->ph_cnt)
		pthread_join(threads[i++], (void *)0);
	free(threads);
}

static void	*ph_action(void *arg)
{
	t_philo		*philo;
	int			eat_cnt;
	t_ph_state	state;

	philo = (t_philo *)arg;
	philo->last_meal_time = philo->start_time;
	eat_cnt = 0;
	while (1)
	{
		state = ph_eat(philo, &eat_cnt);
		if (state == DEAD || state == END)
			return ((void *)0);
		if (ph_sleep(philo) == DEAD)
			return ((void *)0);
		ph_think(philo);
	}
	return ((void *)0);
}
