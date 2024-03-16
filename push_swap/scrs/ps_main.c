/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:26 by subson            #+#    #+#             */
/*   Updated: 2024/03/16 23:33:42 by subson           ###   ########.fr       */
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
	partition_stack(stack_a, stack_b);
	printall(stack_b, "b");
	sort_stack(stack_a, stack_b);

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

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	int		*cmds;
	long	min_stack_a;

	min_stack_a = 0;
	while (stack_b->size)
	{
		cmds = get_cmds(stack_a, stack_b, &min_stack_a);
		execute_cmds(cmds);
	}
}

int	*get_cmds(t_list *stack_a, t_list *stack_b, long *min_stack_a)
{
	long	*cmds;
	long	min_num;
	long	min_index;
	long	i;

	cmds = malloc(sizeof(int) * 12);
	if (!cmds)
		return ((void *)0);
	i = 0;
	while (i < 12)
		cmds[i++] = 0;
	i = 0;
	while (i < stack_b->size)
	{
		cmds[RB] = i;
		if (stack_a->size)
			cmds[RA] = get_index_a(min_stack_a, stack_a, cmds[RB], stack_b);
		if (cal_cmds_num(cmds, stack_a->size, stack_b->size, min_num) < min_num)
		{
			min_num = cmds[0];
			min_index = i;
		}
		i++;
	}
	return (set_cmds(cmds));
}

long	get_index_a(long *min_a, t_list *stack_a, long index_b, t_list *stack_b)
{
	long	i;
	long	value;
	t_node	*node;

	i = 0;
	node = stack_b->head;
	while (i < index_b)
		node = node->next;
	value = node->value;
	i = 0;
	node = stack_a->head;
	while (node->value != *min_a)
	{
		node = node->next;
		i++;
	}
	if (value < *min_a || value > node->prev->value)
		return (i);
	while (node->value < value)
	{
		node = node->next;
		i++;
	}
	return (i % stack_a->size);
}

long	*cal_cmds_num(long *cmds, long asize, long bsize, long *min_num)
{
	long	cmds_num;

	if (cmds[RA] <= (asize / 2) && cmds[RB] <= (bsize / 2))
	{
		if (cmds[RA] < cmds[RB])
			return (cmds[RB]);
		else
			return (cmds[RA]);
	}
	else
	{
		cmds_num = asize - cmds[RA];
		if (cmds_num < bsize - cmds[RB])
			cmds_num = bsize - cmds[RB];
		if (cmds[RA] > (asize / 2) && cmds[RB] > (bsize / 2))
			return (cmds_num);
		if (cmds[RA] + bsize - cmds[RB] < cmds_num)
			cmds_num = cmds[RA] + bsize - cmds[RB];
		else if (cmds[RB] + asize - cmds[RA] < cmds_num)
			cmds_num = cmds[RB] + asize - cmds[RA];
		return (cmds_num);
	}
}

long	*set_cmds(long *cmds) // 수정
{


	bigger_i = 0;
	if (index_ab[0] <= (asize / 2) && index_ab[1] <= (bsize / 2))
	{
		if (index_ab[0] < index_ab[1])
		bigger_i = 1;
		cmds[0] = (int)index_ab[bigger_i];
		cmds[RR] = (int)index_ab[!bigger_i];
		cmds[RA + bigger_i] = (int)(index_ab[bigger_i] - index_ab[!bigger_i]);
	}
	else if (index_ab[0] > (asize / 2) && index_ab[1] > (bsize / 2))
	{
		index_ab[0] = (int)(asize - index_ab[0]);
		index_ab[1] = (int)(bsize - index_ab[1]);
		if (index_ab[0] < index_ab[1])
			bigger_i = 1;
		cmds[0] = index_ab[bigger_i];
		cmds[RRR] = index_ab[!bigger_i];
		cmds[RRA + bigger_i] = index_ab[bigger_i] - index_ab[!bigger_i];
	}
	else if (index_ab[0] > (asize / 2))
	{
		bigger_rrab = (int)(asize - index_ab[0]);
		if (bigger_rrab < (int)(bsize - index_ab[1]))
			bigger_rrab = (int)(bsize - index_ab[1]);
		if (bigger_rrab <= asize - index_ab[0] + index_ab[1])
		{
			// rra rrb -> 두번째 조건이랑 똑같음
		}
		else
		{
			cmds[0] = asize - index_ab[0] + index_ab[1];
			cmds[RRA] = asize - index_ab[0];
			cmds[RB] = index_ab[1];
		}
	}
	else // 고치다 말았음
	{
		bigger_rrab = (int)(asize - index_ab[0]);
		if (bigger_rrab < (int)(bsize - index_ab[1]))
			bigger_rrab = (int)(bsize - index_ab[1]);
		if (bigger_rrab <= index_ab[0] + bsize - index_ab[1])
		{
			// rra rrb -> 두번째 조건이랑 똑같음
		}
		else
		{
			cmds[0] = asize - index_ab[0] + index_ab[1];
			cmds[RA] = index_ab[0];
			cmds[RRB] = bsize - index_ab[1];
		}
	}
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
