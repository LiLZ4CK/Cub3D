/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:06:19 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 02:34:41 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub1d.h"

double	dis(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	check_angle(t_rays	*ray)
{
	ray->rayangle = remainder(ray->rayangle, 2 * PI);
	if (ray->rayangle < 0)
		ray->rayangle += 2 * PI;
}

void	get_2d_view(t_rays *ray)
{
	ray->view_down = 0;
	ray->view_left = 0;
	ray->view_down = 0;
	ray->view_up = 0;
	ray->view_down = (ray->rayangle >= 0 && ray->rayangle < PI);
	ray->view_up = !ray->view_down;
	ray->view_right = (ray->rayangle < 0.5 * PI || ray->rayangle > 1.5 * PI);
	ray->view_left = !ray->view_right;
}

void draw_weapon(t_big *data)
{
	//mlx_put_image_to_window(p->mlx.mlx_ptr, p->mlx.win_ptr, p->weapon.ptr, 0, 0);
	data->weapon.ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./img/weapon.xpm", &data->weapon.width, &data->weapon.height);
	int bpp, size_line, endian;
	data->weapon.data = (unsigned int *)mlx_get_data_addr(data->weapon.ptr, &bpp, &size_line, &endian);

	for (int y = 0; y < data->weapon.height; y++) {
    	for (int x = 0; x < data->weapon.width; x++) {
	        unsigned int pixel = data->weapon.data[y * data->weapon.width + x]; // Get pixel value

        	// Check if the pixel is not yellow (#FFFF00)
            // Draw the pixel on the window, adjusting for position
    	    if (pixel != 0xFFFF00) {
            	mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_ptr, x + 1200 , y+339 , pixel);
        	}
   		}
	}
}

void	cast_rays(t_big *data)
{
	int		i;
	t_rays	*rays;

	i = 0;
	rays = NULL;
	rays = malloc(sizeof(t_rays) * (NUMS_RAYS));
	if (!rays)
		return ;
	while (i < NUMS_RAYS)
	{
		rays[i].rayangle = (data->player.pa - FOV / 4) \
		+ (FOV / 2) / NUMS_RAYS * i;
		rays[i].next_x = 0;
		rays[i].next_y = 0;
		get_dis_rays(data, &rays[i]);
		i++;
	}
	get_3d_map(data, rays);
	free(rays);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
	data->image.ptr, 0, 0);
	draw_weapon(data);
}
