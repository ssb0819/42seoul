/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:10:16 by vscode            #+#    #+#             */
/*   Updated: 2024/06/29 07:18:47 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void			*monitor(void *arg);
static t_ph_state	check_state(t_philos_info *ph_info, int ph_idx, int *end_cnt);

pthread_t	*start_monitoring(t_philos_info *philos_info)
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

static t_ph_state	check_state(t_philos_info *ph_info, int ph_idx, int *end_cnt)
{
	t_ph_state		ph_state;
	int	i;

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
