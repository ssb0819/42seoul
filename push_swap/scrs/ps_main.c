/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:26 by subson            #+#    #+#             */
/*   Updated: 2024/03/14 21:36:38 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = lst_init();
	stack_b = lst_init();
	if (!init_stack(argc, argv, stack_a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printall(stack_a, "a");
	if (set_sorted_index(stack_a))
		printall(stack_a, "a");
	push_swap(stack_a, stack_b);
	printall(stack_b, "b");

}

int	init_stack(int argc, char **argv, t_list *stack_a)
{
	char	**str_p;
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		str_p = &(argv[i]);
		while (**str_p)
		{
			num = ps_strtol(str_p);
			if (num != I_OVERFLOW && !lst_check_dupl(stack_a, num))
			{
				lst_addfirst(stack_a, lst_newnode(num));
				lst_shift(stack_a, UP);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	push_swap(t_list *stack_a, t_list *stack_b)
{
	partition_stack(stack_a, stack_b);
	return (1);
}

void	partition_stack(t_list *stack_a, t_list *stack_b)
{
	long	pivot1;
	long	pivot2;
	long	size;
	long	value;

	pivot1 = stack_a->size / 3 + 1;
	pivot2 = stack_a->size / 3 * 2 + 1;
	size = stack_a->size;
	while (size--)
	{
		value = stack_a->head->value;
		if (value <= pivot1)
		{
			execute_operation(PB, stack_a, stack_b);
			execute_operation(RB, stack_a, stack_b);
		}
		else if (value > pivot1 && value <= pivot2)
			execute_operation(PB, stack_a, stack_b);
		else
			execute_operation(RA, stack_a, stack_b);
	}
	while (stack_a->size)
		execute_operation(PB, stack_a, stack_b);
}

void	execute_operation(t_operation cmd, t_list *stack_a, t_list *stack_b)
{
	if (cmd == SA)
		lst_swap(stack_a);
	else if (cmd == SB)
		lst_swap(stack_b);
	else if (cmd == SS)
	{
		lst_swap(stack_a);
		lst_swap(stack_b);
	}
	else if (cmd == PA)
		lst_addfirst(stack_a, lst_delfirst(stack_b));
	else if (cmd == PB)
		lst_addfirst(stack_b, lst_delfirst(stack_a));
	else
		execute_rotate(cmd, stack_a, stack_b);
	print_cmd(cmd);
	printall(stack_a, "a");
	printall(stack_b, "b");
}

void	execute_rotate(t_operation cmd, t_list *stack_a, t_list *stack_b)
{
	if (cmd == RA)
		lst_shift(stack_a, UP);
	else if (cmd == RB)
		lst_shift(stack_b, UP);
	else if (cmd == RR)
	{
		lst_shift(stack_a, UP);
		lst_shift(stack_b, UP);
	}
	else if (cmd == RRA)
		lst_shift(stack_a, DOWN);
	else if (cmd == RRB)
		lst_shift(stack_b, DOWN);
	else if (cmd == RRR)
	{
		lst_shift(stack_a, DOWN);
		lst_shift(stack_b, DOWN);
	}
}
