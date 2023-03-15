/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_3d_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:45:03 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 15:47:11 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub1d.h"

void	draw_floor(t_big *data, int start, int end, int i)
{
	while (start <= end)
	{
		my_mlx_pixel_put(data, i, start, data->content.ff);
		start++;
	}
}

void	draw_sky(t_big *data, int end, int i)
{
	int	start;

	start = 0;
	while (start < end)
	{
		my_mlx_pixel_put(data, i, start, data->content.cc);
		start++;
	}
}

int	hit_wall(t_big *data, double x, double y)
{
	int	index_x;
	int	index_y;
	int	len;

	index_x = (int)(x / SIZE);
	index_y = (int)(y / SIZE);
	if (x >= data->map.j * SIZE || y >= data->map.i * SIZE || x < 0 || y < 0)
		return (1);
	len = ft_strlen(data->map.map[index_y]);
	if (index_x <= len && data->map.map[index_y][index_x] == '1')
		return (1);
	return (0);
}

void	get_3d_map(t_big *data, t_rays *ray)
{
	t_var	var;
	int		i;
	int		j;

	i = 0;
	while (i < NUMS_RAYS)
	{
		init_3d_variable(&var, &ray[i], data);
		j = var.start;
		draw_sky(data, var.start, i);
		if (ray[i].foundv == 1)
			ray[i].offx = (int)(ray[i].vrzay * 2) % (SIZE_IMG);
		else
			ray[i].offx = (int)(ray[i].horzx * 2) % (SIZE_IMG);
		while (j < var.end)
		{
			get_deriction(data, &ray[i], i, j);
			j++;
		}
		draw_floor(data, var.end, HEIGHT, i);
		i++;
	}	
}
