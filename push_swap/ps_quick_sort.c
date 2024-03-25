/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:17:37 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 23:58:02 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_sorted_index(t_list *list)
{
	t_node	**node_arr;
	t_node	*node;
	long	i;

	node_arr = malloc(sizeof(t_node *) * (list->size));
	if (!list || list->size == 0 || !node_arr)
		return (0);
	i = 0;
	node = list->head;
	while (i < list->size)
	{
		node_arr[i++] = node;
		node = node->next;
	}
	quick_sort(node_arr, 0, (list->size - 1));
	i = 0;
	while (i < list->size)
	{
		node_arr[i]->value = i + 1;
		node = node->next;
		i++;
	}
	free(node_arr);
	return (1);
}

void	quick_sort(t_node **arr, long start, long end)
{
	long	pivot_i;

	if (start < end)
	{
		pivot_i = divide_arr(arr, start, end);
		quick_sort(arr, start, pivot_i - 1);
		quick_sort(arr, pivot_i + 1, end);
	}
}

long	divide_arr(t_node **arr, long start, long end)
{
	long	pivot_i;
	int		pivot;
	long	left;
	long	right;

	pivot_i = (end - start + 1) / 2 + start;
	pivot = arr[pivot_i]->value;
	swap_arr(arr, start, pivot_i);
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && arr[left]->value < pivot)
			left++;
		while (right > start && arr[right]->value > pivot)
			right--;
		if (left < right)
			swap_arr(arr, left, right);
	}
	swap_arr(arr, start, right);
	return (right);
}

void	swap_arr(t_node **arr, long left, long right)
{
	t_node	*temp;

	temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void	copy_move_op(t_move_op *from, t_move_op *to)
{
	to->ra = from->ra;
	to->rra = from->rra;
	to->rb = from->rb;
	to->rrb = from->rrb;
	to->op_comb = from->op_comb;
	to->total = from->total;
}
