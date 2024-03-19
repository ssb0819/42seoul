/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:23 by subson            #+#    #+#             */
/*   Updated: 2024/03/19 21:31:51 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define UP 0
# define DOWN 1
# define A 0
# define B 1
# define I_OVERFLOW 2147483648	// INT_MAX + 1

typedef enum e_operation
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operation;

typedef enum e_op_comb
{
	RR_RA = 0,
	RR_RB,
	RRR_RRA,
	RRR_RRB,
	RA_RRB,
	RRA_RB
}	t_op_comb;

typedef struct s_move_op
{
	long		ra;
	long		rb;
	long		rra;
	long		rrb;
	t_op_comb	op_comb;
	long		total;
}	t_move_op;

// Circular doubly linked list
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	long			value;
}	t_node;

typedef struct s_list
{
	long	size;
	t_node	*head;
}	t_list;

// ps_list.c
t_list	*lst_init(void);
t_node	*lst_newnode(long value);
long	lst_addfirst(t_list *list, t_node *node);
long	lst_add_new_last(t_list *list, long num);
t_node	*lst_delfirst(t_list *list);

// ps_list2.c
int		lst_swap(t_list *list);
int		lst_shift(t_list *list, int direction);
int		lst_check_dupl(t_list *list, long value);
void	lst_del_allnode(t_list *list);
void	lst_free_all(t_list *lists[], int is_error);

// ps_main.c
int		init_stack(int argc, char **argv, t_list *stacks[]);
int		push_swap(t_list *stack_a, t_list *stack_b);
void	partition_stack(t_list *from, t_list *to);
long	ps_strtol(char **str_p);
int		ps_check_format(int *minus_sign, char **str);

// ps_operation.c
void	exe_multi_rotate(t_move_op *op, t_list *stacks[]);
void	exe_op(t_operation op, t_list *stack_a, t_list *stack_b);
void	print_op(t_operation op);

// ps_quick_sort.c
int		set_sorted_index(t_list *list);
void	quick_sort(t_node **arr, long start, long end);
long	divide_arr(t_node **arr, long start, long end);
void	swap_arr(t_node **arr, long left, long right);

// ps_sort_stack.c
int		sort_stack(t_list *from, t_list *to);
void	find_min_move(t_list *stacks[], long *min_sorted, t_move_op *min_move);
long	get_to_index(long *min_sorted, t_list *stack, long target);
void	calc_total_num(t_move_op *move_op);
void	copy_op(t_move_op *from, t_move_op *to);

// debugging
void	printall(t_list *list, char *stack_name);
char	*ft_itoa(int n);

#endif