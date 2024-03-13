/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:48:57 by subson            #+#    #+#             */
/*   Updated: 2024/03/13 22:57:59 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int static	get_len(long n);
void static	set_num(char *array, int len, long n);

char	*ft_itoa(int n)
{
	long	num;
	int		is_negative;
	int		len;
	char	*res;

	is_negative = 0;
	num = n;
	if (n < 0)
	{
		is_negative = 1;
		num *= -1;
		len = get_len(num) + 1;
	}
	else
		len = get_len(num);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return ((void *)0);
	if (is_negative)
		res[0] = '-';
	set_num(res, len, num);
	return (res);
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

void static	set_num(char *array, int len, long n)
{
	array[len] = 0;
	if (n == 0)
		array[0] = '0';
	else
	{
		while (n > 0)
		{
			array[--len] = n % 10 + '0';
			n /= 10;
		}
	}
}

// 디버깅용 나중에 삭제할 것
void	printall(t_list *list, char *stack_name)
{
	int		size;
	t_node	*head;
	char	*value;

	size = list->size;
	head = list->head;
	write(1, "debugging stack-", 16);
	write(1, stack_name, 1);
	write(1, "\t{ ", 3);
	while (size)
	{
		head = head->next;
		value = ft_itoa(head->prev->value);
		while (*value)
			write(1, value++, 1);
		write(1, " ", 1);
		size--;
	}
	size = list->size + '0';
	write(1, "}\tsize: ", 8);
	write(1, &size, 1);
	write(1, "\n", 1);
}