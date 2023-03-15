/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:45:33 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 01:45:44 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub1d.h"

void	get_ver_dis(t_big *data, t_rays *ray)
{
	double	tmpx;

	ray->foundv = 0;
	init_vertical(data, ray);
	while (1)
	{
		tmpx = ray->next_x;
		if (ray->view_left)
			tmpx = tmpx - 1;
		if (hit_wall(data, tmpx, ray->next_y))
		{
			ray->vrzax = ray->next_x;
			ray->vrzay = ray->next_y;
			ray->foundv = 1;
			return ;
		}
			ray->next_x += ray->xsp;
			ray->next_y += ray->ysp;
	}
}

void	get_horz_dis(t_big *data, t_rays *ray)
{
	double	tmpy;

	ray->foundh = 0;
	check_angle(ray);
	get_2d_view(ray);
	init_horizontal(data, ray);
	while (1)
	{
		tmpy = ray->next_y;
		if (ray->view_up)
			tmpy = tmpy - 1;
		if (hit_wall(data, ray->next_x, tmpy))
		{
			ray->horzx = ray->next_x;
			ray->horzy = ray->next_y;
			ray->foundh = 1;
			break ;
		}
			ray->next_x += ray->xsp;
			ray->next_y += ray->ysp;
	}
}

void	get_dis_rays(t_big *data, t_rays *ray)
{
	get_horz_dis(data, ray);
	get_ver_dis(data, ray);
	if (ray->foundh == 1)
		ray->hdis = dis(data->map.jp, data->map.ip, ray->horzx, ray->horzy);
	else
		ray->hdis = INT_MAX;
	if (ray->foundv == 1)
		ray->vdis = dis(data->map.jp, data->map.ip, ray->vrzax, ray->vrzay);
	else
		ray->vdis = INT_MAX;
	if (ray->vdis > ray->hdis)
	{
		ray->foundv = 0;
		ray->dis = ray->hdis;
	}
	else
	{
		ray->foundv = 1;
		ray->dis = ray->vdis;
	}
}
