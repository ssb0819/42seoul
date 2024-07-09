/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sem_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:08:24 by subson            #+#    #+#             */
/*   Updated: 2024/07/09 07:52:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_sems(t_philo *philo, int ph_cnt)
{
	unlink_all_sems();
	philo->forks = sem_open(FORKS_SEM, O_CREAT, 660, ph_cnt);
	philo->print_sem = sem_open(PRINT_SEM, O_CREAT, 660, 1);
	if (philo->forks == SEM_FAILED || philo->print_sem == SEM_FAILED)
		print_err_and_exit("Error: Semaphore open failed\n");
}

void	close_sems(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->print_sem);
}

void	unlink_all_sems(void)
{
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
}
