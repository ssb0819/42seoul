/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:37 by subson            #+#    #+#             */
/*   Updated: 2023/10/19 18:06:04 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = b;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
