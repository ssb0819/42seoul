/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sem_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:08:24 by subson            #+#    #+#             */
/*   Updated: 2024/07/05 22:16:46 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_sems(t_philo *philo, int ph_cnt)
{
	philo->forks = sem_open(FORKS_SEM, O_CREAT, 600, ph_cnt);
	philo->print_sem = sem_open(PRINT_SEM, O_CREAT, 600, 1);
	philo->death_flag.sem = sem_open(D_FLAG_SEM, O_CREAT, 600, 1);
	if (philo->forks == SEM_FAILED || philo->print_sem == SEM_FAILED || \
		philo->death_flag.sem == SEM_FAILED)
		print_err_and_exit("Error: Semaphore open failed\n");
}

void	close_sems_amd_exit(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->print_sem);
	sem_close(philo->death_flag.sem);
	exit(EXIT_SUCCESS);
}

void	unlink_all_sems(void)
{
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
	sem_unlink(D_FLAG_SEM);
}
