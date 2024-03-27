/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:41:01 by subson            #+#    #+#             */
/*   Updated: 2024/03/27 17:18:03 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "push_swap.h"
# include "gnl/get_next_line.h"

t_list		*read_ops(void);
int			exe_and_check(t_list *stacks[], t_list *operations);
t_operation	str_to_op(char *str);
int			sl_strcmp(const char *s1, const char *s2);

#endif