/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:10:09 by subson            #+#    #+#             */
/*   Updated: 2024/07/09 16:10:37 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	last_meal_sem_init(t_philo *philo);
static void	*monitor(void *arg);

void	start_monitoring(t_philo *philo)
{
	pthread_t	*thread;

	last_meal_sem_init(philo);
	thread = malloc(sizeof(pthread_t));
	if (!thread)
		print_err_and_exit("Error: Malloc Error\n");
	pthread_create(thread, (void *)0, monitor, (void *)philo);
	pthread_detach(*thread);
	free(thread);
}

static void	last_meal_sem_init(t_philo *philo)
{
	philo->last_meal.sem_name = make_lm_sem_name(philo->philo_num);
	sem_unlink(philo->last_meal.sem_name);
	philo->last_meal.sem = sem_open(philo->last_meal.sem_name, O_CREAT, 666, 1);
	if (philo->last_meal.sem == SEM_FAILED)
		print_err_and_exit("Error: Semaphore open failed\n");
	unlink(philo->last_meal.sem_name);
}

static void	*monitor(void *arg)
{
	t_philo	*philo;
	long	last_meal_time;

	philo = (t_philo *)arg;
	while (1)
	{
		last_meal_time = get_last_meal_time(&philo->last_meal);
		if (get_timestamp(philo->start_time) - last_meal_time \
				>= philo->time_to_die)
		{
			free(philo->last_meal.sem_name);
			exit(philo->philo_num);
		}
		usleep(900);
	}
}
