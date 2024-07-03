/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:10:16 by vscode            #+#    #+#             */
/*   Updated: 2024/07/03 09:55:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void			create_threads(pthread_t *threads, t_philos_info *ph_info, \
									int odd_even);
static pthread_t	*start_monitoring(t_philos_info *philos_info);
static void			*monitor(void *arg);
static t_ph_state	check_state(t_philos_info *ph_info, \
								int ph_idx, int *end_cnt);

void	simulate(t_philos_info *ph_info)
{
	pthread_t	*monitor;
	pthread_t	*philos;
	int			i;

	monitor = start_monitoring(ph_info);
	philos = malloc(sizeof(pthread_t) * ph_info->ph_cnt);
	if (!philos)
		return ;
	init_start_time(ph_info->philos, ph_info->ph_cnt);
	create_threads(philos, ph_info, ODD);
	usleep(ph_info->philos[0]->time_to_eat / 2 * 1000);
	create_threads(philos, ph_info, EVEN);
	i = 0;
	while (i < ph_info->ph_cnt)
		pthread_join(philos[i++], (void *)0);
	pthread_join(*monitor, (void *)0);
	free(philos);
	free(monitor);
}

static void	create_threads(pthread_t *threads, t_philos_info *ph_info, \
							int odd_even)
{
	int	i;

	i = 0;
	while (i < ph_info->ph_cnt)
	{
		if (i % 2 == odd_even)
			pthread_create(&threads[i], (void *)0, ph_action, \
							(void *)(ph_info->philos[i]));
		i++;
	}
}

static pthread_t	*start_monitoring(t_philos_info *philos_info)
{
	pthread_t		*thread;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		return (0);
	pthread_create(thread, (void *)0, monitor, (void *)philos_info);
	return (thread);
}

static void	*monitor(void *arg)
{
	t_philos_info	*ph_info;
	int				i;
	int				end_cnt;

	ph_info = (t_philos_info *)arg;
	while (1)
	{
		i = 0;
		end_cnt = 0;
		while (i < ph_info->ph_cnt)
		{
			if (check_state(ph_info, i, &end_cnt) == DEAD)
				return ((void *)0);
			i++;
		}
		if (end_cnt == ph_info->ph_cnt)
			return ((void *)0);
		usleep(1000);
	}
}

static t_ph_state	check_state(t_philos_info *ph_info, \
								int ph_idx, int *end_cnt)
{
	t_ph_state	ph_state;
	int			i;

	ph_state = get_ph_state(ph_info->philos[ph_idx]->ph_state);
	i = 0;
	if (ph_state == DEAD)
	{
		while (i < ph_info->ph_cnt)
			set_ph_state(ph_info->philos[i++]->ph_state, DEAD);
		print_dead_msg(ph_info->philos[ph_idx]);
	}
	else if (ph_state == END)
		(*end_cnt)++;
	return (ph_state);
}
