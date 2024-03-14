/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:17:37 by subson            #+#    #+#             */
/*   Updated: 2024/03/14 20:34:20 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_sorted_index(t_list *list)
{
	t_node	**node_arr;
	t_node	*node;
	long	i;

	if (!list || list->size == 0)
		return (0);
	node_arr = malloc(sizeof(t_node*) * (list->size));
	if (!node_arr)
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
	return (1);
}

void	quick_sort(t_node **arr, long start, long end)
{
	if(start < end){
    	long pivot_i = divide_arr(arr, start, end);

    quick_sort(arr, start, pivot_i - 1);
    quick_sort(arr, pivot_i + 1, end);
	}
}

long	divide_arr(t_node **arr, long start, long end)
{
	int		pivot;
	long	left;
	long	right;

	left = start + 1;
	right = end;
	pivot = arr[(start + end) / 2]->value;
	swap_arr(arr, start, (start + end) / 2);
	while (left < right)
	{
		while (arr[left]->value < pivot && left <= right)
			left++;
		while (arr[right]->value > pivot && right >= left)
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
