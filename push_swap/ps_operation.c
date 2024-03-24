/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:25:31 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 18:55:16 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	exe_move_op2(t_move_op *op, t_list *stacks[]);
int static	exe_op2(t_operation op, t_list *stack_a, t_list *stack_b);

void	exe_move_op(t_move_op *op, t_list *stacks[])
{
	if (op->op_comb == RR_RA)
	{
		while (op->rb-- > 0 && op->ra-- > 0)
			exe_op(RR, stacks[A], stacks[B], 1);
		while (op->ra-- > 0)
			exe_op(RA, stacks[A], stacks[B], 1);
	}
	else if (op->op_comb == RR_RB)
	{
		while (op->ra-- > 0 && op->rb-- > 0)
			exe_op(RR, stacks[A], stacks[B], 1);
		while (op->rb-- > 0)
			exe_op(RB, stacks[A], stacks[B], 1);
	}
	else if (op->op_comb == RA_RRB)
	{
		while (op->ra-- > 0)
			exe_op(RA, stacks[A], stacks[B], 1);
		while (op->rrb-- > 0)
			exe_op(RRB, stacks[A], stacks[B], 1);
	}
	else
		exe_move_op2(op, stacks);
	exe_op(PA, stacks[A], stacks[B], 1);
}

void static	exe_move_op2(t_move_op *op, t_list *stacks[])
{
	if (op->op_comb == RRA_RB)
	{
		while (op->rra-- > 0)
			exe_op(RRA, stacks[A], stacks[B], 1);
		while (op->rb-- > 0)
			exe_op(RB, stacks[A], stacks[B], 1);
	}
	else if (op->op_comb == RRR_RRA)
	{
		while (op->rrb-- > 0 && op->rra-- > 0)
			exe_op(RRR, stacks[A], stacks[B], 1);
		while (op->rra-- > 0)
			exe_op(RRA, stacks[A], stacks[B], 1);
	}
	else if (op->op_comb == RRR_RRB)
	{
		while (op->rra-- > 0 && op->rrb-- > 0)
			exe_op(RRR, stacks[A], stacks[B], 1);
		while (op->rrb-- > 0)
			exe_op(RRB, stacks[A], stacks[B], 1);
	}
}

void	exe_op(t_operation op, t_list *stack_a, t_list *stack_b, int will_print)
{
	int	is_done;

	if (op == SA)
		is_done = lst_swap(stack_a);
	else if (op == SB)
		is_done = lst_swap(stack_b);
	else if (op == SS)
	{
		is_done = lst_swap(stack_a);
		is_done = lst_swap(stack_b);
	}
	else if (op == PA)
		is_done = lst_addfirst(stack_a, lst_delfirst(stack_b));
	else if (op == PB)
		is_done = lst_addfirst(stack_b, lst_delfirst(stack_a));
	else
		is_done = exe_op2(op, stack_a, stack_b);
	if (is_done && will_print)
		print_op(op);
	// printall(stack_a, "a");
	// printall(stack_b, "b");
}

int static	exe_op2(t_operation op, t_list *stack_a, t_list *stack_b)
{
	int	is_done;

	is_done = 0;
	if (op == RA)
		is_done = lst_shift(stack_a, UP);
	else if (op == RB)
		is_done = lst_shift(stack_b, UP);
	else if (op == RR)
	{
		is_done = lst_shift(stack_a, UP);
		is_done = lst_shift(stack_b, UP);
	}
	else if (op == RRA)
		is_done = lst_shift(stack_a, DOWN);
	else if (op == RRB)
		is_done = lst_shift(stack_b, DOWN);
	else if (op == RRR)
	{
		is_done = lst_shift(stack_a, DOWN);
		is_done = lst_shift(stack_b, DOWN);
	}
	return (is_done);
}

void	print_op(t_operation op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
	else if (op == PA)
		write(1, "pa\n", 3);
	else if (op == PB)
		write(1, "pb\n", 3);
	else if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RR)
		write(1, "rr\n", 3);
	else if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else if (op == RRR)
		write(1, "rrr\n", 4);
}
