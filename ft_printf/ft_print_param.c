/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:27:12 by subson            #+#    #+#             */
/*   Updated: 2023/11/28 18:46:30 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	len;

	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = (int)ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	print_ptr_address(void *s)
{
	char const		*basenums = "0123456789abcdef";
	unsigned long	address;

	address = (unsigned long)s;
	write(1, "0x", 2);
	put_nbr_base(address, basenums, 16);
	return (get_longlen(address, 16) + 2);
}

int	print_decimal(long n)
{
	char const	*base_nums = "0123456789";
	int			len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len = 1;
	}
	put_nbr_base(n, base_nums, 10);
	len += get_longlen(n, 10);
	return (len);
}

int	print_hexadecimal(int n, char format)
{
	char			*base_nums;
	int				len;
	unsigned int	un;

	if (format == 'x')
		base_nums = "0123456789abcdef";
	else
		base_nums = "0123456789ABCDEF";
	if (n >= 0)
	{
		put_nbr_base(n, base_nums, 16);
		len = get_longlen(n, 16);
	}
	else
	{
		un = (unsigned int)n;
		put_nbr_base(un, base_nums, 16);
		len = get_longlen(un, 16);
	}
	return (len);
}
