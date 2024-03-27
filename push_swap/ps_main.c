/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:26 by subson            #+#    #+#             */
/*   Updated: 2024/03/27 12:46:40 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	static	should_sort_stack(t_list *stacks[])
{
	t_node	*min_sorted;

	if (stacks[A]->size < 4)
	{
		sort_small_stack(stacks[A]);
		return (0);
	}
	if (check_sorted(stacks[A], &min_sorted))
	{
		rotate_stack_a(stacks, min_sorted);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stacks[2];

	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, stacks))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	if (!should_sort_stack(stacks))
	{
		lst_free_all(stacks, 0);
		return (0);
	}
	if (!set_sorted_index(stacks[A]))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	divide_and_move(stacks[A], stacks[B]);
	if (!sort_and_move(stacks[B], stacks[A]))
		lst_free_all(stacks, 1);
	lst_free_all(stacks, 0);
}
