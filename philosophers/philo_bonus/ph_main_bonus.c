/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:47 by root              #+#    #+#             */
/*   Updated: 2024/07/12 18:15:02 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_init(t_philo *philo, char **argv);

int	main(int argc, char **argv)
{
	int		ph_cnt;
	t_philo	philo;

	if (argc < 5)
		print_err_and_exit("Error: Too few args\n");
	ph_cnt = ph_atoi(argv[1]);
	if (ph_cnt <= 0)
		print_err_and_exit("Error: The first arg error\n");
	philo_init(&philo, argv);
	open_sems(&philo, ph_cnt);
	unlink_all_sems();
	simulate(ph_cnt, &philo);
	close_sems(&philo);
}

static void	philo_init(t_philo *philo, char **argv)
{	
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_limit;

	time_to_die = ph_atoi(argv[2]);
	time_to_eat = ph_atoi(argv[3]);
	time_to_sleep = ph_atoi(argv[4]);
	if (time_to_die < 0 || time_to_eat < 0 || time_to_sleep < 0)
		print_err_and_exit("Error: Initialization error - Check the args\n");
	philo->time_to_die = time_to_die;
	philo->time_to_eat = time_to_eat;
	philo->time_to_sleep = time_to_sleep;
	if (argv[5])
	{
		eat_limit = ph_atoi(argv[5]);
		if (eat_limit < 0)
			print_err_and_exit("Error: Initialization error - Check the args\n");
		philo->eat_limit = eat_limit;
	}
	else
		philo->eat_limit = NO_LIMIT;
	philo->start_time = get_timestamp(0);
	philo->last_meal.time = 0;
}
