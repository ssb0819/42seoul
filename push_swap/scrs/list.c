/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:50:39 by subson            #+#    #+#             */
/*   Updated: 2024/03/13 22:52:31 by subson           ###   ########.fr       */
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

t_node	*lst_newnode(int value)
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

int	lst_addfirst(t_list *list, t_node *node)
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
	return(++(list->size));
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

void	lst_swap(t_list *list)
{
	t_node	*new_second;
	t_node	*third;
	t_node	*last;

	if (!list || list->size <= 1)
		return ;
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
}

void	lst_shift(t_list *list, int direction)
{
	if (!list || list->size == 0)
		return ;
	if (direction == UP)
		list->head = list->head->next;
	else if (direction == DOWN)
		list->head = list->head->prev;
}

int	lst_check_dupl(t_list *list, int value)
{
	t_node	*node;
	int		size;

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