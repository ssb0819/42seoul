/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:25 by subson            #+#    #+#             */
/*   Updated: 2024/04/07 18:17:53 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int static	add(t_list **n, t_list **l, void *(*f)(void *), void (*d)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newfirst;
	t_list	*newlst;

	if (!lst || !f || !del)
		return ((void *)0);
	if (!add(&newlst, &lst, f, del))
		return ((void *)0);
	newfirst = newlst;
	lst = lst->next;
	while (lst)
	{
		if (add(&(newlst->next), &lst, f, del))
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

int static	add(t_list **n, t_list **l, void *(*f)(void *), void (*d)(void *))
{
	void	*content;

	content = f((*l)->content);
	if (!content)
		return (0);
	*n = ft_lstnew(content);
	if (!*n)
	{
		d(content);
		return (0);
	}
	return (1);
}
