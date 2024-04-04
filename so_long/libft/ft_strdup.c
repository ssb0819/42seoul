/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:51:59 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 13:18:48 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = (char *)ft_calloc(len + 1, sizeof(char));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}
