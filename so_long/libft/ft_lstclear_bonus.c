/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:28 by subson            #+#    #+#             */
/*   Updated: 2023/11/12 22:16:10 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	if (lst != NULL)
	{
		cur = *lst;
		while (cur != NULL)
		{
			next = cur->next;
			ft_lstdelone(cur, del);
			cur = next;
		}
		*lst = NULL;
	}
}
