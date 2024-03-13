/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:23 by subson            #+#    #+#             */
/*   Updated: 2024/03/13 22:55:45 by subson           ###   ########.fr       */
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
	int				value;
}	t_node;

typedef struct s_list
{
	int		size;
	t_node	*head;
}	t_list;

int		init_stack(int argc, char **argv, t_list *stack_a);
void	execute_operation(t_operation cmd, t_list *stack_a, t_list *stack_b);
void	execute_rotate(t_operation cmd, t_list *stack_a, t_list *stack_b);

t_list	*lst_init(void);
t_node	*lst_newnode(int value);
int		lst_addfirst(t_list *list, t_node *node);
t_node	*lst_delfirst(t_list *list);
void	lst_del_allnode(t_list *list);

void	lst_swap(t_list *list);
void	lst_shift(t_list *list, int direction);
int		lst_check_dupl(t_list *list, int value);

long	ps_strtol(char **str_p);

//디버깅
void	printall(t_list *list, char *stack_name);
char		*ft_itoa(int n);

#endif