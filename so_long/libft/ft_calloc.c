/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:07:23 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 21:53:43 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	const size_t	max = (size_t)-1;
	void			*p;
	size_t			total_len;

	if (size != 0 && count > max / size)
		return ((void *)0);
	total_len = size * count;
	p = malloc(total_len);
	if (!p)
		return ((void *)0);
	ft_bzero(p, total_len);
	return (p);
}
