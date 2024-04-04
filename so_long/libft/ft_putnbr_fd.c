/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:42:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/27 19:40:34 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd);
void static	print_num(long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	print_num(num, fd);
}

void static	print_num(long n, int fd)
{
	char	c;

	if (n >= 10)
		print_num(n / 10, fd);
	c = n + '0';
	write(fd, &c, 1);
}
