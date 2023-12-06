/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/28 18:46:18 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total_len;
	va_list	argptr;

	total_len = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_len += print_param(argptr, format);
		}
		else
		{
			write(1, format, 1);
			total_len++;
		}
		format++;
	}
	return (va_end(argptr), total_len);
}

int	print_param(va_list argptr, const char *format)
{
	if (*format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (*format == 'c')
		return (print_char((char)va_arg(argptr, int)));
	if (*format == 's')
		return (print_str(va_arg(argptr, char *)));
	if (*format == 'p')
		return (print_ptr_address(va_arg(argptr, void *)));
	if (*format == 'd' || *format == 'i')
		return (print_decimal(va_arg(argptr, int)));
	if (*format == 'u')
		return (print_decimal(va_arg(argptr, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (print_hexadecimal(va_arg(argptr, int), *format));
	return (0);
}
