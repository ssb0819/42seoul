/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:36:33 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 18:55:52 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	set_num(t_list *stack, long *first, long *second, long *third);

int	init_stack(int argc, char **argv, t_list *stacks[])
{
	char	**str_p;
	long	num;
	int		i;

	stacks[A] = lst_init();
	stacks[B] = lst_init();
	if (!stacks[A] || !stacks[B])
		return (0);
	i = 0;
	while (++i < argc)
	{
		str_p = &(argv[i]);
		while (**str_p)
		{
			num = ps_strtol(str_p);
			if (num != I_OVERFLOW && !lst_check_dupl(stacks[A], num))
			{
				if (!lst_add_new_last(stacks[A], num))
				{
					lst_del_allnode(stacks[A]);
					return (0);
				}
			}
			else
				return (0);
		}
	}
	return (1);
}

void	partition_stack(t_list *from, t_list *to)
{
	long	pivot1;
	long	pivot2;
	long	size;
	long	value;

	pivot1 = from->size / 3 + 1;
	pivot2 = from->size / 3 * 2 + 1;
	size = from->size;
	while (size-- > 0 && from->size > 3)
	{
		value = from->head->value;
		if (value <= pivot1)
		{
			exe_op(PB, from, to, 1);
			exe_op(RB, from, to, 1);
		}
		else if (value > pivot1 && value <= pivot2)
			exe_op(PB, from, to, 1);
		else
			exe_op(RA, from, to, 1);
	}
	while (from->size > 3)
		exe_op(PB, from, to, 1);
	sort_small_stack(from);
}

int	divide_and_move(t_list *from, t_list *to)
{
	long	count;

	// write(1, "divide\n", 7);
	count = count_unsorted(from);
	if (count == 0)
		return (0);
	else if (from->size / count >= 10)
		move_unsorted(from, to);
	else
		move_all(from, to);
	return (1);
}

long	ps_strtol(char **str)
{
	long	result;
	int		minus_sign;

	if (ps_check_format(&minus_sign, str) == 0)
		return (I_OVERFLOW);
	result = 0;
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
		{
			result = result * 10 + (**str - '0');
			(*str)++;
			if (result > I_OVERFLOW || (result == I_OVERFLOW && minus_sign > 0))
				return (I_OVERFLOW);
		}
		else if (**str == ' ' || (**str >= 9 && **str <= 13))
		{
			while (**str == ' ' || (**str >= 9 && **str <= 13))
				(*str)++;
			return (result * minus_sign);
		}		
		else
			return (I_OVERFLOW);
	}
	return (result * minus_sign);
}

int	ps_check_format(int *minus_sign, char **str)
{
	if (!str || !(*str) || !(**str))
		return (0);
	*minus_sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus_sign *= -1;
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
		return (*minus_sign);
	else
		return (0);
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

void static	set_num(t_list *stack, long *first, long *second, long *third)
{
	*first = stack->head->value;
	*second = stack->head->next->value;
	*third = stack->head->prev->value;
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
