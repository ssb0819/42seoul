/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:25 by subson            #+#    #+#             */
/*   Updated: 2023/11/09 14:42:56 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_add_new(t_list **newlst, t_list **lst, void *(*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newfirst;
	t_list	*newlst;
	void	*content;

	ft_add_new(&newlst, &lst, f);
	newfirst = newlst;
	newlst = newlst->next;
	lst = lst->next;
	while (lst != NULL)
	{
		if (ft_add_new(&newlst, &lst, f))
		{
			newlst = newlst->next;
			lst = lst->next;
		}
		else
			ft_lstclear(&newfirst, del);
	}
}

int	ft_add_new(t_list **newlst, t_list **lst, void *(*f)(void *))
{
	void	*content;

	content = f((*lst)->content);
	if (content == NULL)
		return (0);
	*newlst = ft_lstnew(content);
	if (*newlst == NULL)
		return (0);
}
