/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:02:14 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 18:25:31 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	ft_error(char *str)
{
	write(2, "error: ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	sub_main(t_big *p)
{
	check_path(p->file, ".cub");
	get_contents(p);
	check_map(p);
	check_texture(p);
	get_player(p);
	ckeck_zero(p);
	get_xy(p);
	p->player.pdx = sin(p->player.pa);
	p->player.pdy = cos(p->player.pa);
	p->map.ip = (SIZE * p->map.ip) + (SIZE / 2);
	p->map.jp = (SIZE * p->map.jp) + (SIZE / 2);
	get_colors(p);
}

void	get_colors(t_big *p)
{
	p->content.ff = get_rgb(p->content.fn[0], \
	p->content.fn[1], p->content.fn[2]);
	p->content.cc = get_rgb(p->content.cn[0], \
	p->content.cn[1], p->content.cn[2]);
}

int	get_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	main(int ac, char **av)
{
	t_big	*p;

	if (ac != 2)
		ft_error("arguments !");
	p = malloc(sizeof(t_big));
	p->file = ft_strdup(av[1]);
	sub_main(p);
	p->mlx.mlx_ptr = mlx_init();
	p->image.ptr = mlx_new_image(p->mlx.mlx_ptr, WIDTH, HEIGHT);
	p->image.addr = mlx_get_data_addr(p->image.ptr,
			&p->image.bts_pxt, &p->image.len, &p->image.endn);
	p->mlx.win_ptr = mlx_new_window(p->mlx.mlx_ptr, WIDTH, HEIGHT, "cub3D");
	image_init(p);
	cast_rays(p);
	read_map(p, -1, -4);
	mlx_hook(p->mlx.win_ptr, 2, 1L, ft_mooove, p);
	mlx_hook(p->mlx.win_ptr, 17, 0, mouse, p);
	mlx_hook(p->mlx.win_ptr, 4, 1L << 2, mouse_turn, p);
	mlx_loop(p->mlx.mlx_ptr);
	return (0);
}
