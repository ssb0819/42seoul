/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:41:01 by subson            #+#    #+#             */
/*   Updated: 2024/03/24 17:52:50 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include "push_swap.h"
# include "gnl/get_next_line.h"

int			read_and_exe(t_list *stacks[]);
t_operation	str_to_op(char *str);

#endif