/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:26 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 18:47:10 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacks[2];
	t_node	*min_sorted;

	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, stacks))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	// write(1, "init\n", 5);
	// printall(stacks[A], "a");
	if (stacks[A]->size < 4)
	{
		sort_small_stack(stacks[A]);
		lst_free_all(stacks, 0);
		return (0);
	}
	if (check_sorted(stacks[A], &min_sorted))
	{
		rotate_stack_a(stacks, min_sorted);
		lst_free_all(stacks, 0);
		return (0);
	}
	if (!set_sorted_index(stacks[A]))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	// write(1, "set index\n", 10);
	// printall(stacks[A], "a");
	partition_stack(stacks[A], stacks[B]);
	// printall(stacks[B], "b");
	// write(1, "sort\n", 5);
	if (!sort_and_move(stacks[B], stacks[A]))
		lst_free_all(stacks, 1);
	lst_free_all(stacks, 0);
	// system("leaks push_swap");
}
