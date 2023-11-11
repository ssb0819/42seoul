/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:20:26 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 12:30:17 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = ft_strlen(s);
	uc = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
