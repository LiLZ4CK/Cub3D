/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:36:53 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 18:26:38 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub1d.h"

void	my_mlx_pixel_put(t_big *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return ;
	dst = data->image.addr + (y * data->image.len + x
			* (data->image.bts_pxt / 8));
	*(int *)dst = color;
}

void	init_vertical(t_big *data, t_rays *ray)
{
	ray->xi = floor(data->map.jp / SIZE) * SIZE;
	if (ray->view_right)
		ray->xi += SIZE;
	ray->yi = data->map.ip + (ray->xi - data->map.jp) * tan(ray->rayangle);
	ray->xsp = SIZE;
	if (ray->view_left)
		ray->xsp *= -1;
	ray->ysp = SIZE * tan(ray->rayangle);
	if ((ray->ysp > 0 && ray->view_up)
		|| (ray->ysp < 0 && ray->view_down))
		ray->ysp *= -1;
	ray->next_x = ray->xi;
	ray->next_y = ray->yi;
}

void	init_horizontal(t_big *data, t_rays *ray)
{
	ray->yi = floor(data->map.ip / SIZE) * SIZE;
	if (ray->view_down)
		ray->yi += SIZE;
	ray->xi = data->map.jp + (ray->yi - data->map.ip) / tan(ray->rayangle);
	ray->ysp = SIZE;
	if (ray->view_up)
		ray->ysp *= -1;
	ray->xsp = SIZE / tan(ray->rayangle);
	if ((ray->xsp > 0 && ray->view_left)
		|| (ray->xsp < 0 && ray->view_right))
			ray->xsp *= -1;
	ray->next_x = ray->xi;
	ray->next_y = ray->yi;
}

void	get_correct(t_big *p)
{
	if ((p->player.pdy < MIN && p->player.pdy > 0)
		|| (p->player.pdy > -MIN && p->player.pdy < 0))
		p->player.pdy = 0;
	if ((p->player.pdx < MIN && p->player.pdx > 0)
		|| (p->player.pdx > -MIN && p->player.pdx < 0))
		p->player.pdx = 0;
}
