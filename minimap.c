/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:05:24 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 02:05:10 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	print_map(int j, int i, int color, t_big *p)
{
	int	x_next;
	int	y_next;

	i += 1;
	j += 1;
	i *= 60;
	j *= 60;
	x_next = j + 60;
	y_next = i + 60;
	while (i < y_next)
	{
		j = x_next - 60;
		while (j < x_next)
		{
			mlx_pixel_put(p->mlx.mlx_ptr, p->mlx.win_ptr, j, i, color);
			j++;
		}
		i++;
	}
}

int	long_if(int i, int j, t_big *p)
{
	if ((int)(i + (p->map.ip / SIZE)) <= 0
		|| j + (p->map.jp / SIZE) >= \
		ft_strlen(p->map.map[(int)(p->map.ip / SIZE) + i])
		|| (int)(j + (p->map.jp / SIZE)) < 0)
	{
		return (1);
	}
	return (0);
}

void	read_map(t_big *p, int i, int j)
{
	while (i < 4)
	{
		if (!((i + (p->map.ip / SIZE)) >= p->map.i)
			&& !((i + (p->map.ip / SIZE)) < 0))
		{
			j = -4;
			while (j < 4)
			{
				if (long_if(i, j, p))
					print_map(j, i, 0xAFF24405, p);
				else if (p->map.map[(int)((p->map.ip / SIZE) + i)] \
				[(int)((p->map.jp / SIZE) + j)] == '0')
					print_map(j, i, 0xAF164773, p);
				else
					print_map(j, i, 0xAFF24405, p);
				j++;
			}
		}
		i++;
	}
}
