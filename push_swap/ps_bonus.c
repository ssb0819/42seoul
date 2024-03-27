/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:40:44 by subson            #+#    #+#             */
/*   Updated: 2024/03/27 17:25:18 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*stacks[2];
	t_list	*operations;

	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, stacks))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	operations = read_ops();
	if (!operations)
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	if (exe_and_check(stacks, operations))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_free_all(stacks, 0);
	lst_del_allnode(operations);
	free(operations);
}

t_list	*read_ops(void)
{
	t_list		*ops;
	char		*str;
	t_operation	op;

	ops = lst_init();
	if (!ops)
		return ((void *)0);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		op = str_to_op(str);
		free(str);
		if (op == 0 || lst_add_new_last(ops, (long)op) == 0)
		{
			lst_del_allnode(ops);
			free(ops);
			return ((void *)0);
		}
	}
	return (ops);
}

int	exe_and_check(t_list *stacks[], t_list *operations)
{
	long		i;
	t_node		*cur;
	t_node		*min_sorted;

	i = 0;
	cur = operations->head;
	while (i < operations->size)
	{
		exe_op((t_operation)(cur->value), stacks[A], stacks[B], 0);
		cur = cur->next;
		i++;
	}
	if (stacks[B]->size != 0)
		return (0);
	if (check_sorted(stacks[A], &min_sorted) && min_sorted == stacks[A]->head)
		return (1);
	return (0);
}

t_operation	str_to_op(char *str)
{
	if (!sl_strcmp(str, "sa\n"))
		return (SA);
	if (!sl_strcmp(str, "sb\n"))
		return (SB);
	if (!sl_strcmp(str, "ss\n"))
		return (SS);
	if (!sl_strcmp(str, "pa\n"))
		return (PA);
	if (!sl_strcmp(str, "pb\n"))
		return (PB);
	if (!sl_strcmp(str, "ra\n"))
		return (RA);
	if (!sl_strcmp(str, "rb\n"))
		return (RB);
	if (!sl_strcmp(str, "rr\n"))
		return (RR);
	if (!sl_strcmp(str, "rra\n"))
		return (RRA);
	if (!sl_strcmp(str, "rrb\n"))
		return (RRB);
	if (!sl_strcmp(str, "rrr\n"))
		return (RRR);
	return (0);
}

int	sl_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
