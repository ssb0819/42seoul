/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:26 by subson            #+#    #+#             */
/*   Updated: 2024/03/22 20:23:13 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	set_num(t_list *stack, long *first, long *second, long *third);

int	main(int argc, char **argv)
{
	t_list	*stacks[2];

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
	// write(1, "set index\n", 10);
	if (!set_sorted_index(stacks[A]))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	// printall(stacks[A], "a");
	partition_stack(stacks[A], stacks[B]);	
	// printall(stacks[B], "b");
	// write(1, "sort\n", 5);
	if (!sort_and_move(stacks[B], stacks[A]))
		lst_free_all(stacks, 1);
	lst_free_all(stacks, 0);
}

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
	while (size--)
	{
		value = from->head->value;
		if (value <= pivot1)
		{
			exe_op(PB, from, to);
			exe_op(RB, from, to);
		}
		else if (value > pivot1 && value <= pivot2)
			exe_op(PB, from, to);
		else
			exe_op(RA, from, to);
	}
	while (from->size)
		exe_op(PB, from, to);
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
			exe_op(SA, stack, (void *)0);
		return ;
	}
	if (first > second && first > third)
		exe_op(RA, stack, (void *)0);
	set_num(stack, &first, &second, &third);
	if (second > first && second > third)
		exe_op(RRA, stack, (void *)0);
	set_num(stack, &first, &second, &third);
	if (first > second)
		exe_op(SA, stack, (void *)0);
}

void static	set_num(t_list *stack, long *first, long *second, long *third)
{
	*first = stack->head->value;
	*second = stack->head->next->value;
	*third = stack->head->prev->value;
}
