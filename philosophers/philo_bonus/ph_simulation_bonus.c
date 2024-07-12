/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_simulation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:14:23 by subson            #+#    #+#             */
/*   Updated: 2024/07/12 18:20:35 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static pid_t	*create_all_philos(int ph_cnt, t_philo *philo);
static void		create_philo(int odd_even, t_philo *philo, int ph_cnt, \
								pid_t *ph_pids);
static void		kill_all_philos(pid_t *ph_pids, int ph_cnt);

void	simulate(int ph_cnt, t_philo *philo)
{
	int		i;
	int		status;
	int		dead_flag;
	pid_t	*ph_pids;

	ph_pids = create_all_philos(ph_cnt, philo);
	i = 0;
	dead_flag = 0;
	while (i < ph_cnt)
	{
		waitpid(-1, &status, 0);
		if (!dead_flag && WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			kill_all_philos(ph_pids, ph_cnt);
			printf("%ld %d %s\n", get_timestamp(philo->start_time), \
					WEXITSTATUS(status), "died");
			dead_flag = 1;
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}

static pid_t	*create_all_philos(int ph_cnt, t_philo *philo)
{
	pid_t	*ph_pids;

	ph_pids = malloc_wrapper(sizeof(pid_t) * ph_cnt);
	create_philo(ODD, philo, ph_cnt, ph_pids);
	if (ph_cnt > 1)
	{
		usleep(philo->time_to_eat / 2 * 1000);
		create_philo(EVEN, philo, ph_cnt, ph_pids);
	}
	return (ph_pids);
}

static void	create_philo(int odd_even, t_philo *philo, int ph_cnt, \
							pid_t *ph_pids)
{
	int		i;
	pid_t	pid;

	i = odd_even;
	while (i < ph_cnt)
	{
		philo->philo_num = i + 1;
		pid = fork();
		if (pid > 0)
		{
			ph_pids[i] = pid;
			i += 2;
			continue ;
		}
		else if (pid == 0)
			ph_action(philo);
		else
		{
			unlink_all_sems();
			print_err_and_exit("Error: Fork Error\n");
		}
	}
}

static void	kill_all_philos(pid_t *ph_pids, int ph_cnt)
{
	int	i;

	i = 0;
	while (i < ph_cnt)
		kill(ph_pids[i++], SIGINT);
}
