/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:22:24 by subson            #+#    #+#             */
/*   Updated: 2024/06/29 07:18:00 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philos_info	ph_info;
	pthread_t		*monitor;

	if (argc < 5)
		return (print_err("Error: Too few arguments\n"));
	ph_info.ph_cnt = ph_atoi(argv[1]);
	if (ph_info.ph_cnt <= 0)
		return (print_err("Error: Num_of_philosopher must be greater than 0\n"));
	if (!philo_init(&ph_info, argv))
		return (print_err("Error: Initialization error\n"));
	monitor = start_monitoring(&ph_info);
	simulate(&ph_info);
	pthread_join(*monitor, (void *)0);
	free(monitor);
	clean_all_philos(&ph_info);
	return (0);
}
