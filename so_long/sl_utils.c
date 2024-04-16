/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subson <subson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:18:31 by subson            #+#    #+#             */
/*   Updated: 2024/04/16 21:33:01 by subson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

void	exit_on_error(t_err_types e_type, char *err_msg)
{
	if (e_type == SYSTEM_ERR)
		perror(err_msg);
	else if (e_type == RUNTIME_ERR)
		ft_putstr_fd(err_msg, 2);
	exit(1);
}

int	sl_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_move_count(t_param *param)
{
	char	*mv_cnt_str;

	param->move_count++;
	mv_cnt_str = ft_itoa(param->move_count);
	if (!mv_cnt_str)
		exit_on_error(SYSTEM_ERR, ERR_MSG);
	ft_putstr_fd(mv_cnt_str, 1);
	ft_putstr_fd("\n", 1);
	free(mv_cnt_str);
}

void	free_2d_array(char **array, int len)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < len)
	{
		if (*array[i])
			free(array[i]);
		i++;
	}
	free(array);
}
