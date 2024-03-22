/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:45:44 by subson            #+#    #+#             */
/*   Updated: 2024/03/22 20:11:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_unsorted(t_list *stack)
{
	long	count;
	long	i;

	i = 0;
	count = 0;
	while (i < stack->size)
	{
		i++;
	}
	return (count);
}

void	move_unsorted(t_list *from, t_list *to)
{
	long	tmp;
	long	tmp2;

	tmp = from->size;
	tmp2 = to->size;
}

void	move_all(t_list *from, t_list *to)
{
	long	pivot1;
	long	pivot2;
	long	size;
	long	value;

	pivot1 = from->size / 3 + 1;
	pivot2 = from->size / 3 * 2 + 1;
	size = from->size;
	while (size--)
	{
		value = from->head->value;
		if (value <= pivot1)
		{
			exe_op(PB, from, to);
			exe_op(RB, from, to);
		}
		else if (value > pivot1 && value <= pivot2)
			exe_op(PB, from, to);
		else
			exe_op(RA, from, to);
	}
	while (from->size)
		exe_op(PB, from, to);
}
