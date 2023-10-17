/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:37 by subson            #+#    #+#             */
/*   Updated: 2023/10/17 21:22:01 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{	
	unsigned char	*tmp;
	unsigned char	uc;

	tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0)
	{
		*tmp = uc;
		tmp++;
		n--;
	}
	return (s);
}
