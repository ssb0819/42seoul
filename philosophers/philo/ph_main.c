/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:22:24 by subson            #+#    #+#             */
/*   Updated: 2024/07/11 11:56:23 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philos_info	ph_info;

	if (argc < 5)
		return (print_err("Error: Too few args\n"));
	memset(&ph_info, 0, sizeof(t_philos_info));
	ph_info.ph_cnt = ph_atoi(argv[1]);
	if (ph_info.ph_cnt <= 0)
		return (print_err("Error: The first arg must be greater than 0\n"));
	if (!philo_init(&ph_info, argv))
	{
		clean_all_philos(&ph_info);
		return (print_err("Error: Initialization error - Check the args\n"));
	}
	simulate(&ph_info);
	clean_all_philos(&ph_info);
	return (0);
}
