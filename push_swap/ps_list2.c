/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:38:53 by subson            #+#    #+#             */
/*   Updated: 2024/03/22 22:33:46 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_swap(t_list *list)
{
	t_node	*new_second;
	t_node	*third;
	t_node	*last;

	if (!list || list->size <= 1)
		return (0);
	new_second = list->head;
	if (list->size != 2)
	{
		third = list->head->next->next;
		last = list->head->prev;
	}
	else
	{
		third = list->head->next;
		last = new_second;
	}
	list->head = list->head->next;
	last->next = list->head;
	list->head->next = new_second;
	new_second->next = third;
	third->prev = new_second;
	new_second->prev = list->head;
	list->head->prev = last;
	return (1);
}

int	lst_shift(t_list *list, int direction)
{
	if (!list || list->size <= 1)
		return (0);
	if (direction == UP)
		list->head = list->head->next;
	else if (direction == DOWN)
		list->head = list->head->prev;
	return (1);
}

int	lst_check_dupl(t_list *list, long value)
{
	t_node	*node;
	long	size;

	if (!list || list->size == 0)
		return (0);
	size = list->size;
	node = list->head;
	while (size)
	{
		if (node->value == value)
			return (1);
		node = node->next;
		size--;
	}
	return (0);
}

void	lst_free_all(t_list *lists[], int is_error)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (lists[i])
		{
			lst_del_allnode(lists[i]);
			free(lists[i]);
		}
		i++;
	}
	if (is_error)
		write(1, "Error\n", 6);
}

void	lst_del_allnode(t_list *list)
{
	t_node	*node;

	if (!list)
		return ;
	while (list->size)
	{
		node = list->head;
		list->head = list->head->next;
		free(node);
		(list->size)--;
	}
	list->head = (void *)0;
}
