/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:13:34 by subson            #+#    #+#             */
/*   Updated: 2023/11/28 18:36:38 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_param(va_list argptr, const char *format);
int		print_char(char c);
int		print_str(char *s);
int		print_ptr_address(void *s);
int		print_int(int n);
int		print_u_int(unsigned int n);
int		print_hexadecimal(int n, char format);
int		get_longlen(unsigned long n, int base);
int		print_decimal(long n);
void	put_nbr_base(unsigned long n, char const *base_n, unsigned long base);
size_t	ft_strlen(char *s);

#endif