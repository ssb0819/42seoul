/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:30:39 by subson            #+#    #+#             */
/*   Updated: 2024/04/06 21:50:35 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (0);
	new->next = *lst;
	*lst = new;
	return (1);
}
