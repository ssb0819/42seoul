/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:08:24 by subson            #+#    #+#             */
/*   Updated: 2024/06/25 19:12:11 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_forks_flag(t_philo **philos, t_dead_flag *d_flag, int ph_cnt);
static int	set_time_args(t_philo **philos, int ph_cnt, char **argv);
static int	set_std_mutex(t_philo **philos, int cnt);
static int	set_etc(t_philo **philos, int cnt, char *eat_limit_str);

int	philo_init(t_philos_info *ph_info, char **argv)
{
	t_dead_flag	*dead_flag;

	dead_flag = malloc(sizeof(t_dead_flag));
	if (!dead_flag)
		return (0);
	ph_info->philos = (t_philo **)make_array(sizeof(t_philo), ph_info->ph_cnt);
	if (!*ph_info->philos)
		return (0);
	if (!set_forks_flag(ph_info->philos, dead_flag, ph_info->ph_cnt))
		return (0);
	if (!set_time_args(ph_info->philos, ph_info->ph_cnt, argv))
		return (0);
	if (!set_std_mutex(ph_info->philos, ph_info->ph_cnt))
		return (0);
	if (!set_etc(ph_info->philos, ph_info->ph_cnt, argv[5]))
		return (0);
	return (1);
}

static int	set_forks_flag(t_philo **philos, t_dead_flag *d_flag, int ph_cnt)
{
	t_fork	**forks;
	int		i;

	forks = (t_fork **)make_array(sizeof(t_fork), ph_cnt);
	if (!forks)
		return (0);
	if (!init_fork_mutex(forks, ph_cnt) || \
		pthread_mutex_init(&d_flag->mutex, (void *)0) < 0)
	{
		free_array((void **)forks, ph_cnt);
		return (0);
	}
	d_flag->flag = DEAD;
	i = 0;
	while (i < ph_cnt)
	{
		philos[i]->dead_flag = d_flag;
		philos[i]->left = forks[i];
		if (i != 0)
			philos[i]->right = forks[i - 1];
		i++;
	}
	philos[0]->right = forks[i - 1];
	free(forks);
	return (1);
}

static int	set_time_args(t_philo **philos, int ph_cnt, char **argv)
{
	int	i;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	i = 0;
	time_to_die = ph_atoi(argv[2]);
	time_to_eat = ph_atoi(argv[3]);
	time_to_sleep = ph_atoi(argv[4]);
	if (time_to_die < 0 || time_to_eat < 0 || time_to_sleep < 0)
		return (0);
	while (i < ph_cnt)
	{
		philos[i]->time_to_die = time_to_die;
		philos[i]->time_to_eat = time_to_eat;
		philos[i]->time_to_sleep = time_to_sleep;
		i++;
	}
	return (1);
}

static int	set_std_mutex(t_philo **philos, int cnt)
{
	int				i;
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (0);
	if (pthread_mutex_init(mutex, (void *)0) < 0)
	{
		free(mutex);
		return (0);
	}
	i = 0;
	while (i < cnt)
	{
		philos[i]->std_mutex = mutex;
		i++;
	}
	return (1);
}

static int	set_etc(t_philo **philos, int cnt, char *eat_limit_str)
{
	int		i;
	int		eat_limit;

	i = 0;
	eat_limit = 0;
	if (eat_limit_str)
		eat_limit = ph_atoi(eat_limit_str);
	while (i < cnt)
	{
		philos[i]->philo_num = i + 1;
		if (eat_limit > 0)
			philos[i]->eat_limit = eat_limit;
		else
			philos[i]->eat_limit = 0;
		i++;
	}
	return (1);
}
