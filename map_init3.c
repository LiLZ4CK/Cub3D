/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:03:35 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 02:04:00 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	check_last(t_big *p, int i)
{
	int	j;

	j = 0;
	while (p->map.map[i][j])
	{
		if (p->map.map[i][j] != '1' && p->map.map[i][j] != ' ')
			ft_error("wrong map !");
		j++;
	}
}

void	ckeck_zero(t_big *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map.map[i + 1])
	{
		j = -1;
		while (p->map.map[i][++j])
		{
			if (p->map.map[i][j] == '0')
			{
				if (i == 0 || j == 0 || j == ft_strlen(p->map.map[i]) - 1
					|| j >= ft_strlen(p->map.map[i + 1]))
					ft_error("wrong map !");
				else if (check_zerov2(p->map.map[i + 1][j])
					|| check_zerov2(p->map.map[i - 1][j])
					|| check_zerov2(p->map.map[i][j + 1])
					|| check_zerov2(p->map.map[i][j - 1]))
					ft_error("wrong map !");
			}
		}
		i++;
	}
	check_last(p, i);
}

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

void	check_path(char *str, const char *s)
{
	int		i;
	int		j;

	i = ft_strlen(str) - 4;
	if (i < 1)
		ft_error("wrong format !");
	j = 0;
	while (str[i] || s[j])
	{
		if (str[i] != s[j])
			ft_error("wrong format !");
		i++;
		j++;
	}
}

void	mini_map(t_big *p)
{
	int	i;
	int	j;

	i = 66;
	read_map(p, -1, -4);
	while (i < 113)
	{
		j = 66;
		while (j < 113)
			mlx_pixel_put(p->mlx.mlx_ptr, p->mlx.win_ptr, i, j++, 0x5FCDD9);
		i++;
	}
	i = 0;
	while (i < 25)
	{
		mlx_pixel_put(p->mlx.mlx_ptr, p->mlx.win_ptr, 90 + \
		(i * cos(p->player.pa)), 90 + (i * sin(p->player.pa)), RED);
		i++;
	}
}
