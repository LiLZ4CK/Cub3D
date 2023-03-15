/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:34:04 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 19:03:42 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	content_init(t_big *p)
{
	p->content.c = 0;
	p->content.f = 0;
	p->content.no = 0;
	p->content.so = 0;
	p->content.we = 0;
	p->content.ea = 0;
	p->i = 0;
	p->j = 0;
	p->fd = open(p->file, O_RDONLY);
	if (p->fd == -1)
		ft_error("cannot use this file !");
	p->line = get_next_line(p->fd);
}

void	get_xy(t_big *p)
{
	int	i;

	i = 0;
	while (p->map.map[i])
	{
		if (ft_strlen(p->map.map[i]) > p->map.j)
			p->map.j = ft_strlen(p->map.map[i]);
		i++;
	}
}

void	image_init(t_big *p)
{
	p->texture.n_orth = get_texture_image(p, p->content.north_p);
	p->texture.s_outh = get_texture_image(p, p->content.south_p);
	p->texture.e_ast = get_texture_image(p, p->content.east_p);
	p->texture.w_est = get_texture_image(p, p->content.west_p);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->len + x * (img->bts_pxt / 8));
	*(int *)pixel = color;
}

int	ft_instr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
