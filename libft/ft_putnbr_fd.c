/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:42:42 by subson            #+#    #+#             */
/*   Updated: 2023/11/11 15:31:27 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd);
int static	get_len(unsigned int n);
void		print_num(int len, unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un *= -1;
	}
	print_num(get_len(un) - 1, un, fd);
}

int static	get_len(unsigned int n)
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

void	print_num(int cnt, unsigned int n, int fd)
{
	unsigned int	tmp;
	unsigned int	num;

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
