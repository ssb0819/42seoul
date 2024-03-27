/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:36:33 by subson            #+#    #+#             */
/*   Updated: 2024/03/27 12:45:43 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int argc, char **argv, t_list *stacks[])
{
	char	*str_p;
	long	num;
	int		i;

	stacks[A] = lst_init();
	stacks[B] = lst_init();
	if (!stacks[A] || !stacks[B])
		return (0);
	i = 0;
	while (++i < argc)
	{
		str_p = argv[i];
		while (*str_p)
		{
			num = ps_strtol(&str_p);
			if (num != I_OVERFLOW && !lst_check_dupl(stacks[A], num))
				if (lst_add_new_last(stacks[A], num))
					continue ;
			return (0);
		}
	}
	if (stacks[A]->size == 0)
		return (0);
	return (1);
}

int	check_sorted(t_list *stack, t_node **min_sorted)
{
	t_node	*cur;
	long	i;

	i = 0;
	*min_sorted = stack->head;
	cur = stack->head->next;
	while (i < stack->size - 1)
	{
		if (cur->value < (*min_sorted)->value)
			*min_sorted = cur;
		cur = cur->next;
		i++;
	}
	i = 0;
	cur = *min_sorted;
	while (i < stack->size - 1)
	{
		if (cur->next->value < cur->value)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}

void static	set_num(t_list *stack, long *first, long *second, long *third)
{
	*first = stack->head->value;
	*second = stack->head->next->value;
	*third = stack->head->prev->value;
}

void	sort_small_stack(t_list *stack)
{
	long	first;
	long	second;
	long	third;

	if (stack->size < 2)
		return ;
	set_num(stack, &first, &second, &third);
	if (stack->size == 2)
	{
		if (first > second)
			exe_op(SA, stack, (void *)0, 1);
		return ;
	}
	if (first > second && first > third)
		exe_op(RA, stack, (void *)0, 1);
	set_num(stack, &first, &second, &third);
	if (second > first && second > third)
		exe_op(RRA, stack, (void *)0, 1);
	set_num(stack, &first, &second, &third);
	if (first > second)
		exe_op(SA, stack, (void *)0, 1);
}

void	rotate_stack_a(t_list *stack[], t_node *min_p)
{
	long	i;
	long	a_size;
	t_node	*cur;

	a_size = stack[A]->size;
	if (a_size <= 1)
		return ;
	i = 0;
	cur = stack[A]->head;
	while (cur != min_p)
	{
		cur = cur->next;
		i++;
	}
	if (i < a_size / 2)
		while (i-- > 0)
			exe_op(RA, stack[A], stack[B], 1);
	else
		while ((a_size--) - i > 0)
			exe_op(RRA, stack[A], stack[B], 1);
}
