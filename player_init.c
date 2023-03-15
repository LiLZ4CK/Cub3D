/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:01:51 by zwalad            #+#    #+#             */
/*   Updated: 2022/12/31 14:17:05 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	get_player2(t_big *p, int ort)
{
	p->map.ort = ort;
	if (ort == north)
		p->player.pa = (double)(PI * 3) / 2;
	else if (ort == south)
		p->player.pa = PI / 2;
	else if (ort == east)
		p->player.pa = 0;
	else if (ort == west)
		p->player.pa = PI;
	p->map.map[p->map.i][p->map.j] = '0';
	p->map.ip = p->map.i;
	p->map.jp = p->map.j;
	p->map.player++;
	if (p->map.player > 1)
		ft_error("only oneplayer !");
}

void	get_player1(t_big *p)
{
	if (p->map.map[p->map.i][p->map.j] == 'N')
		get_player2(p, north);
	else if (p->map.map[p->map.i][p->map.j] == 'S')
		get_player2(p, south);
	else if (p->map.map[p->map.i][p->map.j] == 'E')
		get_player2(p, east);
	else if (p->map.map[p->map.i][p->map.j] == 'W')
		get_player2(p, west);
}

void	get_player(t_big *p)
{
	p->map.i = -1;
	p->map.player = 0;
	while (p->map.map[++p->map.i])
	{
		p->map.j = -1;
		while (p->map.map[p->map.i][++p->map.j])
		{
			if (p->map.map[p->map.i][p->map.j] == 'N'
				|| p->map.map[p->map.i][p->map.j] == 'S'
				|| p->map.map[p->map.i][p->map.j] == 'E'
				|| p->map.map[p->map.i][p->map.j] == 'W')
				get_player1(p);
		}
	}
	if (p->map.player != 1)
		ft_error("try to put a player in your map !");
}

void	get_dataa2(t_big *p)
{
	p->image.ptr = mlx_new_image(p->mlx.mlx_ptr, 0, 0);
	p->image.addr = mlx_get_data_addr(p->image.ptr, &p->image.bts_pxt, \
	&p->image.len, &p->image.endn);
}

void	get_dataa(t_big *p)
{
	if (p->map.ort == north)
		return (get_dataa2(p));
	else if (p->map.ort == south)
		return (get_dataa2(p));
	else if (p->map.ort == west)
		return (get_dataa2(p));
	else if (p->map.ort == east)
		return (get_dataa2(p));
}
