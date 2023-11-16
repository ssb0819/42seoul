/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/16 16:12:41 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#define BUF_SIZE 1024

int	ft_printf(const char *format, ...)
{
	char	buf[BUF_SIZE];
	size_t	buf_idx;
	va_list	argptr;

	buf_idx = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (format == '%')
		{
			format++;
			set_to_buf(&buf, &buf_idx, get_param(argptr, format));
		}
		else
		{
			set_to_buf(&buf, &buf_idx, format);
			format++;
		}
	}
	
}

char	*get_param(va_list argptr, const char *const format)
{
	const char	*percent = "%";

	if (*format == '%')
		return (percent);
	if (*format == 'c')
		return (get_char(va_arg(argptr, char)));
	if (*format == 's')
		return (get_str(va_arg(argptr, char *)));
	if (*format == 'd' || *format == 'i')
		return (get_int(va_arg(argptr, int)));
	if (*format == 'u')
		return (get_unsigned_int(va_arg(argptr, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (get_hexadecimal(va_arg(argptr, int), *format));
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