/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_last_meal_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:52:24 by subson            #+#    #+#             */
/*   Updated: 2024/07/09 15:07:33 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int static	get_len(long n);

long	get_last_meal_time(t_last_meal *last_meal)
{
	long	last_meal_time;

	sem_wait(last_meal->sem);
	last_meal_time = last_meal->time;
	sem_post(last_meal->sem);
	return (last_meal_time);
}

void	set_last_meal_time(t_last_meal *last_meal, long last_meal_time)
{
	sem_wait(last_meal->sem);
	last_meal->time = last_meal_time;
	sem_post(last_meal->sem);
}

char	*make_lm_sem_name(int n)
{
	long	num;
	int		len;
	char	*res;

	num = n;
	len = get_len(num) + 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((void *)0);
	res[0] = 's';
	res[len] = '\0';
	while (num > 0)
	{
		res[--len] = num % 10 + '0';
		num /= 10;
	}
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
