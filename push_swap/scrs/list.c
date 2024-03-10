/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:50:39 by subson            #+#    #+#             */
/*   Updated: 2024/03/10 20:08:18 by subson           ###   ########.fr       */
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

int	lst_addfirst(t_list *list, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	if (list->size == 0)
	{
		list->head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = list->head->prev;
		new_node->next = list->head;
		list->head->prev->next = new_node;
		list->head->prev = new_node;
		list->head = new_node;
	}
	(list->size)++;
	return (1);
}

void	lst_delfirst(t_list *list)
{
	t_node	*first_node;

	if (list->size == 0)
		return ;
	first_node = list->head;
	if (list->size != 1)
	{
		list->head->prev->next = list->head->next;
		list->head->next->prev = list->head->prev;
		list->head = list->head->next;
	}
	else
		list->head = (void *)0;
	free(first_node);
	(list->size)--;
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