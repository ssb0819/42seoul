/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:22:24 by subson            #+#    #+#             */
/*   Updated: 2024/06/14 20:32:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo		**philos;
	t_last_meal	*last_meals;
	int			philo_cnt;

	if (argc < 5)
		return (0);
	philo_cnt = ph_atoi(argv[1]);
	if (philo_cnt <= 0)
		return (0);
	philos = make_philos(philo_cnt);
	if (!philos)
		return (0);
	if (set_args(philos, argv) && set_forks(philos, philo_cnt) && set_etc()) // set_etc 이름 바꾸고 구현 시작
		start_simulation();
	else
		return (0);
}

t_philo	**make_philos(int philo_cnt)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * (philo_cnt + 1));
	if (!philos)
		return ((void *)0);
	memset(philos, 0, sizeof(t_philo *) * (philo_cnt + 1));
	i = 0;
	while (i < philo_cnt)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			while (i)
				free(philos[--i]);
			free(philos);
			return ((void *)0);
		}
		memset(philos[i], 0, sizeof(t_philo));
		i++;
	}
	philos[i] = (void *)0;
	return (philos);
}

int	set_args(t_philo **philos, char **argv)
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_limit;

	time_to_die = ph_atoi(argv[1]);
	time_to_eat = ph_atoi(argv[2]);
	time_to_sleep = ph_atoi(argv[3]);
	eat_limit = 0;
	if (argv[4])
		eat_limit = ph_atoi(argv[4]);
	if (time_to_die < 0 || time_to_eat < 0 || \
		time_to_sleep < 0 || eat_limit < 0)
		return (0);
	while (*philos)
	{
		(*philos)->time_to_die = time_to_die;
		(*philos)->time_to_eat = time_to_eat;
		(*philos)->time_to_sleep = time_to_sleep;
		(*philos)->eat_limit = eat_limit;
		philos++;
	}
	return (1);
}

int	set_forks(t_philo **philos, int philo_cnt)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = make_forks(philo_cnt);
	if (!forks)
		return (0);
	i = 0;
	while (i < philo_cnt)
	{
		if (pthread_mutex_init(forks[i], (void *)0) < 0)
		{
			free_all_forks(forks, philo_cnt);
			return (0);
		}
		philos[i]->left_fork = forks[i];
		if (i > 0)
			philos[i]->right_fork = forks[i - 1];
	}
	philos[0]->right_fork = forks[philo_cnt - 1];
	free(forks);
	return (1);
}

pthread_mutex_t	**make_forks(int cnt)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t *) * cnt);
	if (!forks)
		return ((void *)0);
	memset(forks, 0, sizeof(pthread_mutex_t *) * cnt);
	i = 0;
	while (i < cnt)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!forks[i])
		{
			free_all_forks(forks, i);
			return ((void *)0);
		}
		i++;
	}
	return (forks);
}

void	free_all_forks(pthread_mutex_t **forks, int cnt)
{
	int	i;

	if (!forks)
		return ;
	i = 0;
	while (i < cnt || forks[i])
	{
		free(forks[i]);
		i++;
	}
	free(forks);
}
