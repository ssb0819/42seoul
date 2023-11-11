/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:38:35 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 13:57:34 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);
int static	get_len(unsigned int n);
void static	set_num(char *array, int len, unsigned int n);

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				is_negative;
	int				len;
	char			*res;

	is_negative = 0;
	un = n;
	if (n < 0)
	{
		is_negative = 1;
		un *= -1;
		len = get_len(un) + 1;
	}
	else
		len = get_len(un);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (is_negative)
		res[0] = '-';
	set_num(res, len, un);
	return (res);
}

int static	get_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void static	set_num(char *array, int len, unsigned int n)
{
	array[len] = 0;
	if (n == 0)
		array[0] = '0';
	else
	{
		while (n > 0)
		{
			array[--len] = n % 10 + '0';
			n /= 10;
		}
	}
}	
