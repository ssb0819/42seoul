/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:57:59 by subson            #+#    #+#             */
/*   Updated: 2024/06/25 17:39:24 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_fork_init(t_philo **philos, int ph_cnt)
{
	int		i;
	t_fork	*prev;

	i = 0;
	printf("=== init check start ===\n");
	if (philos[0]->right != philos[ph_cnt - 1]->left)
		printf("philo_num 1 fork init error\n");
	while (i < ph_cnt)
	{
		if (i != 0 && philos[i]->right != prev)
			printf("philo_num %d fork init error\n", philos[i]->philo_num);
		prev = philos[i]->left;
		i++;
	}
	printf("=== init check end ===\n");
}

void	print_debug(t_philo *philo, char *msg)
{
	long	timestamp;

	timestamp = get_timestamp(philo->start_time);
	pthread_mutex_lock(philo->std_mutex);
	printf("[debug] %ld %d %s\n", timestamp, philo->philo_num, msg);
	pthread_mutex_unlock(philo->std_mutex);
}
