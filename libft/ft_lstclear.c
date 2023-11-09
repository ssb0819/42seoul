/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:28 by subson            #+#    #+#             */
/*   Updated: 2023/11/09 13:39:49 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	if (lst != NULL && *lst != NULL)
	{
		cur = *lst;
		next = cur->next;
		while (cur != NULL)
		{
			ft_lstdelone(cur, del);
			cur = next;
			if (cur != NULL)
				next = cur->next;
		}
		lst = NULL;
	}
}
