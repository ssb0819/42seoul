/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:18:46 by subson            #+#    #+#             */
/*   Updated: 2023/10/29 20:17:03 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONG_MAX 9223372036854775807

int	is_in_range(long cur, char next, int len, long minus_sign)
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


int	ft_atoi(const char *str)
{
	long	result;
	long	minus_sign;
	int		i;

	result = 0;
	minus_sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minus_sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (is_in_range(result, str[i], i + 1, minus_sign))
			{
				result = result * 10 + (str[i] - '0');
				i++;
			}
			else
			{
				if (minus_sign > 0)
					return (-1);
				else
					return (0);
			}
		}
		else
			return (result * minus_sign);
	}
	return (result * minus_sign);
}


// #include <stdlib.h>
// #include <stdio.h>

// int	main(){

// 	const char s[] = "9223372036854775810";
// 	int atoi_i = atoi(s);
// 	long strtol_l = strtol(s, (char **)NULL, 10);
	
// 	printf("atoi : %d\n", atoi_i);
// 	printf("strtol : %ld\n", strtol_l);

// 	printf("LONG_MIN : %ld\n", LONG_MIN);
// 	printf("LONG_MAX : %ld\n", LONG_MAX);

// 	printf("%ld\n", LONG_MAX / 10);

// 	return (0);
// }