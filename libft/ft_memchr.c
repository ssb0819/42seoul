/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:16:00 by subson            #+#    #+#             */
/*   Updated: 2023/10/25 18:49:44 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;

	us = (unsigned char *)s;
	while (n > 0 && *us)
	{
		if (*us == c)
			return ((void *)us);
		us++;
		n--;
	}
	return (0);
}
