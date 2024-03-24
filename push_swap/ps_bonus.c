/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:40:44 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 19:47:44 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int static	ft_strcmp(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	t_list	*stacks[2];
	t_node	*min;

	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, stacks))
	{
		lst_free_all(stacks, 1);
		return (0);
	}
	if (read_and_exe(stacks) && stacks[B]->size == 0)
	{
		if (check_sorted(stacks[A], &min) && min == stacks[A]->head)
		{
			write(1, "OK\n", 3);
			lst_free_all(stacks, 0);
			return (0);
		}
	}
	printall(stacks[A], "a");
	write(1, "KO\n", 3);
	lst_free_all(stacks, 0);
}

int	read_and_exe(t_list *stacks[])
{
	char		*str;
	t_operation	op;

	str = get_next_line(0);
	while (str)
	{
		op = str_to_op(str);
		if (!op)
		{
			free(str);
			return (0);
		}
		exe_op(op, stacks[A], stacks[B], 0);
		free(str);
		str = get_next_line(0);
	}
	return (1);
}

t_operation	str_to_op(char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (SA);
	if (!ft_strcmp(str, "sb\n"))
		return (SB);
	if (!ft_strcmp(str, "ss\n"))
		return (SS);
	if (!ft_strcmp(str, "pa\n"))
		return (PA);
	if (!ft_strcmp(str, "pb\n"))
		return (PB);
	if (!ft_strcmp(str, "ra\n"))
		return (RA);
	if (!ft_strcmp(str, "rb\n"))
		return (RB);
	if (!ft_strcmp(str, "rr\n"))
		return (RR);
	if (!ft_strcmp(str, "rra\n"))
		return (RRA);
	if (!ft_strcmp(str, "rrb\n"))
		return (RRB);
	if (!ft_strcmp(str, "rrr\n"))
		return (RRR);
	return (0);
}

int static	ft_strcmp(const char *s1, const char *s2)
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
