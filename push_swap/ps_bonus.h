/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:41:01 by subson            #+#    #+#             */
/*   Updated: 2024/03/27 13:03:23 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "push_swap.h"
# include "gnl/get_next_line.h"

int			read_and_exe(t_list *stacks[]);
t_operation	str_to_op(char *str);

#endif