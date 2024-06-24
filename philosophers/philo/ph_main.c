/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:22:24 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 18:01:54 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philos_info	ph_info;

	if (argc < 5)
		return (print_err("Error: Too few arguments\n"));
	ph_info.ph_cnt = ph_atoi(argv[1]);
	if (ph_info.ph_cnt <= 0)
		return (print_err("Error: Num_of_philosopher must be greater than 0\n"));
	if (philo_init(&ph_info, argv) && start_monitoring(&ph_info))
		simulate(&ph_info);
	free_all_philos(&ph_info);
	return (0);
}
