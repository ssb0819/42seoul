/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:48:51 by subson            #+#    #+#             */
/*   Updated: 2024/06/25 15:45:49 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	test_func(int i, ...)
{
	va_list	argptr;
	char	*arg;

	va_start(argptr, i);
	arg = (char *)va_arg(argptr, char *);
	va_end(argptr);
}
