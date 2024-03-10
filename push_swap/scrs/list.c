/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:50:39 by subson            #+#    #+#             */
/*   Updated: 2024/03/10 23:06:37 by subson           ###   ########.fr       */
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

void	lst_addfirst(t_list *list, t_node *node)
{
	if (!node)
		return ;
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
	(list->size)++;
}

t_node	*lst_delfirst(t_list *list)
{
	t_node	*first_node;

	if (list->size == 0)
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

void	lst_delall(t_list *list)
{
	while (list->size)
	{
		list->head = list->head->next;
		free(list->head->prev);
		(list->size)--;
	}
	list->head = (void *)0;
}

// 디버깅용 나중에 삭제할 것
void	printall(t_list *list, char *stack_name)
{
	int		size;
	t_node	*head;
	int		value;

	size = list->size;
	head = list->head;
	write(1, "debugging stack-", 16);
	write(1, stack_name, 1);
	write(1, "\t{ ", 3);
	while (size)
	{
		head = head->next;
		value = head->prev->value + '0';
		write(1, &value, 1);
		write(1, " ", 1);
		size--;
	}
	write(1, "}\n", 2);
}

void	lst_swap(t_list *list)
{
	t_node	*new_second;
	t_node	*third;
	t_node	*last;

	if (list->size <= 1)
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

void	lst_push(t_list *from, t_list *to)
{
	lst_addfirst(to, lst_delfirst(from));
}

void	lst_shift(t_list *list, int direction)
{

}