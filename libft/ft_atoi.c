/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:18:46 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 15:45:10 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONG_MAX 9223372036854775807

int			ft_atoi(const char *str);
void static	ft_strtol(long *result, const char *str, int minus_sign);
int static	is_in_range(long cur, char next, int len, long minus_sign);

int	ft_atoi(const char *str)
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
	ft_strtol(&result, str, minus_sign);
	return ((int)result);
}

void static	ft_strtol(long *result, const char *str, int minus_sign)
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
				if (minus_sign > 0)
					*result = -1;
				else
					*result = 0;
				break ;
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
	if (len == 19)
		return (0);
	if (cur > LONG_MAX / 10)
		return (0);
	if (cur == LONG_MAX / 10 && next > max_last)
		return (0);
	return (1);
}
