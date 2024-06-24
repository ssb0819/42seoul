/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:38:26 by subson            #+#    #+#             */
/*   Updated: 2024/06/24 13:18:41 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	**make_array(size_t size, int cnt)
{
	void	**arr;
	int		i;

	arr = malloc(sizeof(void *) * cnt);
	if (!arr)
		return ((void **)0);
	i = 0;
	while (i < cnt)
	{
		arr[i] = malloc(size);
		memset(arr[i], 0, size);
		if (!arr[i])
		{
			free_array(arr, i);
			return ((void *)0);
		}
		i++;
	}
	return (arr);
}

void	free_array(void **arr, int cnt)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < cnt)
		free(arr[i++]);
	free(arr);
}
