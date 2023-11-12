/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:25 by subson            #+#    #+#             */
/*   Updated: 2023/11/12 23:35:09 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int static	add(t_list **n, t_list **l, void *(*f)(void *), void (*d)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newfirst;
	t_list	*newlst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!add(&newlst, &lst, f, del))
		return (NULL);
	newfirst = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		if (add(&(newlst->next), &lst, f, del))
		{
			newlst = newlst->next;
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newfirst, del);
			return (NULL);
		}
	}
	return (newfirst);
}

int static	add(t_list **n, t_list **l, void *(*f)(void *), void (*d)(void *))
{
	void	*content;

	content = f((*l)->content);
	if (content == NULL)
		return (0);
	*n = ft_lstnew(content);
	if (*n == NULL)
	{
		d(content);
		return (0);
	}
	return (1);
}
