/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:22:29 by subson            #+#    #+#             */
/*   Updated: 2024/03/14 20:22:05 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	static	check_str_format(int *minus_sign, char **str)
{
	if (!str || !(*str) || !(**str))
		return (0);
	*minus_sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus_sign *= -1;
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
		return (*minus_sign);
	else
		return (0);
}

long	ps_strtol(char **str)
{
	long	result;
	int		minus_sign;

	if (check_str_format(&minus_sign, str) == 0)
		return (I_OVERFLOW);
	result = 0;
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
		{
			result = result * 10 + (**str - '0');
			(*str)++;
			if (result > I_OVERFLOW || (result == I_OVERFLOW && minus_sign > 0))
				return (I_OVERFLOW);
		}
		else if (**str == ' ' || (**str >= 9 && **str <= 13))
		{
			while (**str == ' ' || (**str >= 9 && **str <= 13))
				(*str)++;
			return (result * minus_sign);
		}		
		else
			return (I_OVERFLOW);
	}
	return (result * minus_sign);
}
