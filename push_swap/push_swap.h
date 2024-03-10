/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:23 by subson            #+#    #+#             */
/*   Updated: 2024/03/10 19:56:03 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

t_list	*lst_init(void);
int		lst_addfirst(t_list *list, int value);
void	lst_delfirst(t_list *list);
void	lst_delall(t_list *list);
void	printall(t_list *list, char *stack_name); // 디버깅용 - 삭제예정


#endif