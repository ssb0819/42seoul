/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:07:49 by subson            #+#    #+#             */
/*   Updated: 2024/03/25 20:21:42 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_and_move(t_list *from, t_list *to)
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
	free(min_move);
	return (1);
}

void	find_min_move(t_list *stacks[], t_node **min_p, t_move_op *min_move)
{
	t_move_op	cur_move;
	t_node		*cur;
	t_node		*new_min_p;

	cur = stacks[B]->head;
	cur_move.rb = 0;
	min_move->total = I_OVERFLOW;
	while (cur_move.rb < stacks[B]->size)
	{
		cur_move.ra = get_to_index(min_p, stacks[A], cur->value);
		cur_move.rra = stacks[A]->size - cur_move.ra;
		cur_move.rrb = stacks[B]->size - cur_move.rb;
		cur_move.total = cur_move.ra;
		cur_move.op_comb = RR_RA;
		calc_total_num(&cur_move);
		if (cur_move.total < min_move->total)
		{
			copy_move_op(&cur_move, min_move);
			new_min_p = cur;
		}
		cur = cur->next;
		cur_move.rb++;
	}
	if (!(*min_p) || (*min_p)->value > new_min_p->value)
		*min_p = new_min_p;
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
