/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:20:26 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 21:35:40 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = ft_strlen(s);
	uc = (unsigned char)c;
	while (i > 0)
	{
		if (s[i] == uc)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == uc)
		return ((char *)(s + i));
	return (0);
}
