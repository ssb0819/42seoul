/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:00 by subson            #+#    #+#             */
/*   Updated: 2024/07/03 08:53:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEBUG_H
# define PHILO_DEBUG_H

# include "../includes/philosophers.h"

/* debug */
void	check_fork_init(t_philo **philos, int ph_cnt);
void	print_debug(t_philo *philo, char *msg);

#endif