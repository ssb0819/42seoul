/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:50:39 by subson            #+#    #+#             */
/*   Updated: 2024/03/19 21:31:42 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lst_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return ((void *)0);
	list->head = (void *)0;
	list->size = 0;
	return (list);
}

t_node	*lst_newnode(long value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ((void *)0);
	node->value = value;
	node->prev = (void *)0;
	node->next = (void *)0;
	return (node);
}

long	lst_addfirst(t_list *list, t_node *node)
{
	if (!list || !node)
		return (0);
	if (list->size == 0)
	{
		list->head = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = list->head->prev;
		node->next = list->head;
		list->head->prev->next = node;
		list->head->prev = node;
		list->head = node;
	}
	return (++(list->size));
}

long	lst_add_new_last(t_list *list, long num)
{
	t_node	*node;
	long	size;

	node = lst_newnode(num);
	if (!node)
		return (0);
	size = lst_addfirst(list, node);
	lst_shift(list, UP);
	return (size);
}

t_node	*lst_delfirst(t_list *list)
{
	t_node	*first_node;

	if (!list || list->size == 0)
		return ((void *)0);
	first_node = list->head;
	if (list->size != 1)
	{
		list->head->prev->next = list->head->next;
		list->head->next->prev = list->head->prev;
		list->head = list->head->next;
	}
	else
		list->head = (void *)0;
	(list->size)--;
	return (first_node);
}
