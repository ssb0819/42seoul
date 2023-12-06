/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:50:58 by subson            #+#    #+#             */
/*   Updated: 2023/11/28 18:59:28 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	put_nbr_base(unsigned long n, char const *base_nums, unsigned long base)
{
	if (n >= base)
		put_nbr_base(n / base, base_nums, base);
	write(1, &(base_nums[n % base]), 1);
}

int	get_longlen(unsigned long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
