/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:23 by subson            #+#    #+#             */
/*   Updated: 2024/03/14 21:35:33 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define UP 1
# define DOWN 0
# define I_OVERFLOW 2147483648

typedef enum e_operation
{
	SA,
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

// ps_main.c
int		init_stack(int argc, char **argv, t_list *stack_a);
void	execute_operation(t_operation cmd, t_list *stack_a, t_list *stack_b);
void	execute_rotate(t_operation cmd, t_list *stack_a, t_list *stack_b);
int		push_swap(t_list *stack_a, t_list *stack_b);
void	partition_stack(t_list *stack_a, t_list *stack_b);

// ps_list.c
t_list	*lst_init(void);
t_node	*lst_newnode(long value);
long	lst_addfirst(t_list *list, t_node *node);
t_node	*lst_delfirst(t_list *list);
void	lst_del_allnode(t_list *list);

int		lst_swap(t_list *list);
int		lst_shift(t_list *list, int direction);
int		lst_check_dupl(t_list *list, long value);

// ps_utils.c
long	ps_strtol(char **str_p);

// ps_sort.c
int		set_sorted_index(t_list *list);
void	quick_sort(t_node **arr, long start, long end);
long	divide_arr(t_node **arr, long start, long end);
void	swap_arr(t_node **arr, long left, long right);

//디버깅
void	printall(t_list *list, char *stack_name);
char	*ft_itoa(int n);
void	print_cmd(t_operation cmd);

#endif