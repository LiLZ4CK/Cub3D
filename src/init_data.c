/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:38:58 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 19:08:35 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub1d.h"

void	init_3d_variable(t_var *var, t_rays *ray, t_big *data)
{
	var->disttowall = ray->dis * (cos(ray->rayangle - data->player.pa));
	var->disttoplan = (WIDTH / 2) / tan(FOV / 2);
	var->projplan = (SIZE / var->disttowall) * var->disttoplan;
	ray->wall = (int)var->projplan;
	var->start = (HEIGHT / 2) - (var->projplan / 2);
	if (var->start < 0 || var->start >= HEIGHT)
		var->start = 0;
	var->end = ((HEIGHT) / 2) + (var->projplan / 2);
	if (var->end >= HEIGHT || var->end < 0)
		var->end = HEIGHT;
}

int	get_my_color(t_image *img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y > HEIGHT)
		return (-1);
	dst = img->addr + (y * img->len + x * (img->bts_pxt / 8));
	return (*(int *)dst);
}

t_image	*get_texture_image(t_big *p, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image) * 1);
	img->addr = 0;
	img->endn = 0;
	img->len = 0;
	img->bts_pxt = 0;
	img->ptr = mlx_xpm_file_to_image(p->mlx.mlx_ptr, path, \
	&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bts_pxt, \
	&img->len, &img->endn);
	return (img);
}

void	get_deriction(t_big *data, t_rays *ray, int i, int j)
{
	int		color;
	int		dst;

	dst = (j + (ray->wall / 2)) - (HEIGHT / 2);
	ray->offy = (dst) * ((float)SIZE_IMG / ray->wall);
	color = 0;
	if (ray->view_up && !ray->foundv)
		color = get_my_color(data->texture.n_orth, ray->offx, ray->offy);
	else if (ray->view_down && !ray->foundv)
		color = get_my_color(data->texture.s_outh, ray->offx, ray->offy);
	else if (ray->view_left && ray->foundv == 1)
		color = get_my_color(data->texture.e_ast, ray->offx, ray->offy);
	else if (ray->view_right && ray->foundv == 1)
		color = get_my_color(data->texture.w_est, ray->offx, ray->offy);
	my_mlx_pixel_put(data, i, j, color);
}

void	exito(t_big *p)
{
	int	i;

	i = 0;
	while (p->map.map[i])
		free(p->map.map[i++]);
	free(p->map.map);
	free(p->texture.e_ast->addr);
	free(p->texture.w_est->addr);
	free(p->texture.n_orth->addr);
	free(p->texture.s_outh->addr);
	free(p->texture.n_orth);
	free(p->texture.s_outh);
	free(p->texture.e_ast);
	free(p->texture.w_est);
	free(p->content.north_p);
	free(p->content.south_p);
	free(p->content.west_p);
	free(p->content.east_p);
	free(p->content.cn);
	free(p->content.fn);
	free(p->file);
	free(p);
	exit(0);
}
