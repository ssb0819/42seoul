/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:42:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/14 01:00:36 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd);
int static	get_len(long n);
void static	print_num(int len, long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	print_num(get_len(num) - 1, num, fd);
}

int static	get_len(long n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void static	print_num(int cnt, long n, int fd)
{
	long	tmp;
	long	num;

	while (cnt)
	{
		tmp = cnt;
		num = n;
		while (tmp)
		{
			num /= 10;
			tmp--;
		}
		num = num % 10 + '0';
		ft_putchar_fd((char)num, fd);
		cnt--;
	}
	num = n % 10 + '0';
	ft_putchar_fd((char)num, fd);
}
