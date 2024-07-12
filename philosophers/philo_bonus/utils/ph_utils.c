/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:22:53 by subson            #+#    #+#             */
/*   Updated: 2024/07/12 17:27:46 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_err_and_exit(char *err_msg)
{
	printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

void	*malloc_wrapper(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		print_err_and_exit("Error: Malloc error\n");
	return (result);
}
