/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:05:51 by subson            #+#    #+#             */
/*   Updated: 2024/06/14 19:36:41 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#define INT_MAX 2147483647

void static	get_result(long *result, const char *str, int minus_sign);
int static	is_in_range(long cur, char next, int len, long minus_sign);

int	ph_atoi(const char *str)
{
	int		minus_sign;
	long	result;

	minus_sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		minus_sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	get_result(&result, str, minus_sign);
	return ((int)result);
}

void static	get_result(long *result, const char *str, int minus_sign)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (is_in_range(*result, str[i], i, minus_sign))
			{
				*result = *result * 10 + (str[i] - '0');
				i++;
			}
			else
			{
				*result = -1;
				return ;
			}
		}
		else
			break ;
	}
	*result *= minus_sign;
}

int static	is_in_range(long cur, char next, int len, long minus_sign)
{
	char	max_last;

	if (minus_sign > 0)
		max_last = '7';
	else
		max_last = '8';
	if (len == 10)
		return (0);
	if (cur > INT_MAX / 10)
		return (0);
	if (cur == INT_MAX / 10 && next > max_last)
		return (0);
	return (1);
}
