/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:07:49 by subson            #+#    #+#             */
/*   Updated: 2024/03/22 22:47:09 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_and_move(t_list *from, t_list *to)
{
	t_move_op	*min_move;
	t_list		*stacks[2];
	t_node		*sorted_min;

	min_move = malloc(sizeof(t_move_op));
	if (!min_move)
		return (0);
	sorted_min = to->head;
	stacks[B] = from;
	stacks[A] = to;
	while (stacks[B]->size)
	{
		find_min_move(stacks, &sorted_min, min_move);
		exe_move_op(min_move, stacks);
	}
	rotate_stack_a(stacks, sorted_min);
	return (1);
}

void	find_min_move(t_list *stacks[], t_node **sorted_min, t_move_op *min_move)
{
	t_move_op	move_op;
	long		min_num;
	long		from_index;
	t_node		*cur;
	t_node		*target;

	from_index = 0;
	min_num = I_OVERFLOW;
	cur = stacks[B]->head;

	// write(1, "\nfind_minimal_move - min_stack_to :", 35);
	// if (*sorted_min)
	// {
	// 	(*sorted_min)->value += '0';
	// 	write(1, &((*sorted_min)->value), 1);
	// 	(*sorted_min)->value -= '0';
	// 	write(1, "\n", 1);
	// }
	// else
	// 	write(1, "0\n", 2);

	while (from_index < stacks[B]->size)
	{
		move_op.ra = get_to_index(sorted_min, stacks[A], cur->value);
		move_op.rb = from_index;
		move_op.rra = stacks[A]->size - move_op.ra;
		move_op.rrb = stacks[B]->size - move_op.rb;
		move_op.total = move_op.ra;
		move_op.op_comb = RR_RA;
		calc_total_num(&move_op);
		if (move_op.total < min_num)
		{
			min_num = move_op.total;
			copy_move_op(&move_op, min_move);
			target = cur;
		}
		cur = cur->next;
		from_index++;
	}
	if (!(*sorted_min) || (*sorted_min)->value > target->value)
		*sorted_min = target;
}

long	get_to_index(t_node **min_p, t_list *stack, long target)
{
	long	to_index;
	t_node	*cur;

	if (stack->size == 0)
		return (0);
	to_index = 0;
	cur = stack->head;
	while (cur != *min_p)
	{
		cur = cur->next;
		to_index++;
	}
	if (target < cur->value || target > cur->prev->value)
		return (to_index);
	while (cur->value < target)
	{
		cur = cur->next;
		to_index++;
	}
	to_index %= stack->size;
	return (to_index);
}

void	calc_total_num(t_move_op *move_op)
{
	if (move_op->total < move_op->rb)
	{
		move_op->total = move_op->rb;
		move_op->op_comb = RR_RB;
	}
	if (move_op->total > move_op->ra + move_op->rrb)
	{
		move_op->total = move_op->ra + move_op->rrb;
		move_op->op_comb = RA_RRB;
	}
	if (move_op->total > move_op->rra + move_op->rb)
	{
		move_op->total = move_op->rra + move_op->rb;
		move_op->op_comb = RRA_RB;
	}
	if (move_op->total > move_op->rra && move_op->rra >= move_op->rrb)
	{
		move_op->total = move_op->rra;
		move_op->op_comb = RRR_RRA;
	}
	else if (move_op->total > move_op->rrb && move_op->rrb > move_op->rra)
	{
		move_op->total = move_op->rrb;
		move_op->op_comb = RRR_RRB;
	}
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
			exe_op(RA, stack[A], stack[B]);
	else
		while ((a_size--) - i > 0)
			exe_op(RRA, stack[A], stack[B]);
}
