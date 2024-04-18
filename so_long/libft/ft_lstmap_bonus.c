/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:25 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 22:07:07 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add(t_list **new_lst, t_list *old_lst, \
					void *(*func)(void *), void (*del)(void *))
{
	void	*content;

	content = func(old_lst->content);
	if (!content)
		return (0);
	*new_lst = ft_lstnew(content);
	if (!*new_lst)
	{
		del(content);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newfirst;
	t_list	*newlst;

	if (!lst || !f || !del)
		return ((void *)0);
	if (!add(&newlst, lst, f, del))
		return ((void *)0);
	newfirst = newlst;
	lst = lst->next;
	while (lst)
	{
		if (add(&(newlst->next), lst, f, del))
		{
			newlst = newlst->next;
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newfirst, del);
			return ((void *)0);
		}
	}
	return (newfirst);
}
