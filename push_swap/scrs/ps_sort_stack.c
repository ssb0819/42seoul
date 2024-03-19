/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:07:49 by subson            #+#    #+#             */
/*   Updated: 2024/03/19 21:27:08 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_stack(t_list *from, t_list *to)
{
	t_move_op	*min_move;
	long		min_sorted;
	t_list		*stacks[2];

	min_move = malloc(sizeof(t_move_op));
	if (!min_move)
		return (0);
	min_sorted = 0;
	stacks[B] = from;
	stacks[A] = to;
	min_move->ra = 0;
	min_move->rb = 0;
	min_move->rra = 0;
	min_move->rrb = 0;
	while (stacks[B]->size)
	{
		find_min_move(stacks, &min_sorted, min_move);
		exe_multi_rotate(min_move, stacks);
	}
	return (1);
}

void	find_min_move(t_list *stacks[], long *min_sorted, t_move_op *min_move)
{
	t_move_op	move_op;
	long		min_num;
	long		from_index;
	t_node		*tmp_node;

	from_index = 0;
	min_num = I_OVERFLOW;
	tmp_node = stacks[B]->head;
	while (from_index < stacks[B]->size)
	{
		move_op.ra = get_to_index(min_sorted, stacks[A], tmp_node->value);
		move_op.rb = from_index;
		move_op.rra = stacks[A]->size - move_op.ra;
		move_op.rrb = stacks[B]->size - move_op.rb;
		move_op.total = move_op.ra;
		move_op.op_comb = RR_RA;
		calc_total_num(&move_op);
		if (move_op.total < min_num)
			copy_op(&move_op, min_move);
		tmp_node = tmp_node->next;
		from_index++;
	}
}

long	get_to_index(long *min_sorted, t_list *stack, long target)
{
	long	to_index;
	t_node	*node;

	if (stack->size == 0)
		return (0);
	to_index = 0;
	node = stack->head;
	while (node->value != *min_sorted)
	{
		node = node->next;
		to_index++;
	}
	if (target < *min_sorted)
	{
		*min_sorted = target;
		return (to_index);
	}
	if (target > node->prev->value)
		return (to_index);
	while (node->value < target)
	{
		node = node->next;
		to_index++;
	}
	return (to_index % stack->size);
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

void	copy_op(t_move_op *from, t_move_op *to)
{
	to->ra = from->ra;
	to->rra = from->rra;
	to->rrb = from->rb;
	to->rrb = from->rrb;
	to->op_comb = from->op_comb;
}
