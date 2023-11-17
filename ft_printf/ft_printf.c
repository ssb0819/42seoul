/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/17 17:14:44 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		total_len;
	va_list	argptr;

	total_len = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (format != '%')
		{
			write(1, format, 1);
			total_len++;
			format++;
		}
		else
		{
			format++;
			print_param(argptr, format);
		}
	}
	
}

char	*print_param(va_list argptr, const char *format)
{
	const char	*percent = "%";

	if (*format == '%')
		return (percent);
	if (*format == 'c')
		return (print_char(va_arg(argptr, char)));
	if (*format == 's')
		return (print_str(va_arg(argptr, char *)));
	if (*format == 'd' || *format == 'i')
		return (print_int(va_arg(argptr, int)));
	if (*format == 'u')
		return (print_unsigned_int(va_arg(argptr, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (print_hexadecimal(va_arg(argptr, int), *format));
	return ((char *)format);
}

#include <stdio.h>

void testit (int i, ...)
{
    va_list argptr; // 가변인자 리스트를 가리키는 포인터
    va_start(argptr, i); // 가변인자 리스트 포인터를 첫 주소로 초기화

    if (i == 0)
    {
    	// int 타입 사이즈 만큼의 데이터를 반환하고, 포인터를 sizeof(int) 만큼 이동
        int n = va_arg(argptr, int); 
        printf("%d\n", n);
    }
    else
    {
    	// char * 타입 사이즈 만큼의 데이터를 반환하고, 포인터를 sizeof(char *) 만큼 이동
        char *s = va_arg(argptr, char*);
        printf("%s\n", s);
    }
	
    // argptr = NULL 로 가변인자 사용을 끝마침을 표시
    va_end(argptr);
}