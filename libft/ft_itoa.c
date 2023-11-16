/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:38:35 by subson            #+#    #+#             */
/*   Updated: 2023/11/14 00:42:08 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);
int static	get_len(long n);
void static	set_num(char *array, int len, long n);

char	*ft_itoa(int n)
{
	long	num;
	int		is_negative;
	int		len;
	char	*res;

	is_negative = 0;
	num = n;
	if (n < 0)
	{
		is_negative = 1;
		num *= -1;
		len = get_len(num) + 1;
	}
	else
		len = get_len(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (is_negative)
		res[0] = '-';
	set_num(res, len, num);
	return (res);
}

int static	get_len(long n)
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

void static	set_num(char *array, int len, long n)
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
