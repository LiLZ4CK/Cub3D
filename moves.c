/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:33:05 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/06 00:02:49 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

int	mouse_turn(int keycode, int i, int j, t_big *p)
{
	int	s;

	s = 1;
	(void)j;
	(void)keycode;
	if (i > WIDTH / 2)
		s = -1;
	p->player.pa -= (PI / 40) * s;
	if ((p->player.pa - (PI / 60)) < 0)
		p->player.pa += 2 * PI;
	else if ((p->player.pa + (PI / 60)) > 2 * PI)
		p->player.pa = 0;
	p->player.pdy = cos(p->player.pa);
	p->player.pdx = sin(p->player.pa);
	get_correct(p);
	cast_rays(p);
	mini_map(p);
	return (0);
}

int	mouse(int keycode, t_big *p)
{
	(void)keycode;
	(void)p;
	exit(0);
	return (0);
}

int	ifmove(t_big *p, int ip, int jp)
{
	int	i;
	int	j;

	i = (p->map.ip / SIZE);
	j = (p->map.jp / SIZE);
	if (ip <= 0 || jp <= 0 || ip >= p->map.i || jp >= ft_strlen(p->map.map[ip]))
		return (0);
	if (p->map.map[ip][jp] == '1' || p->map.map[i][jp] == '1'
		|| p->map.map[ip][j] == '1')
		return (0);
	return (1);
}

void	ft_mooove2(int keycode, t_big *p, int s)
{
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 124)
			s = -1;
		p->player.pa -= (PI / 40) * s;
		if ((p->player.pa - (PI / 60)) < 0)
			p->player.pa += 2 * PI;
		else if ((p->player.pa + (PI / 60)) > 2 * PI)
			p->player.pa = 0;
		p->player.pdy = cos(p->player.pa);
		p->player.pdx = sin(p->player.pa);
	}
	if (keycode == 13 && ifmove(p, ((p->map.ip + (p->player.pdx * STEPS)) \
	/ SIZE), (p->map.jp + (p->player.pdy * STEPS)) / SIZE))
	{
		p->map.ip += p->player.pdx * STEPS;
		p->map.jp += p->player.pdy * STEPS;
	}
	if (keycode == 1 && ifmove(p, ((p->map.ip - (p->player.pdx * STEPS)) \
	/ SIZE), (p->map.jp - (p->player.pdy * STEPS)) / SIZE))
	{
		p->map.ip -= p->player.pdx * STEPS;
		p->map.jp -= p->player.pdy * STEPS;
	}
}

int	ft_mooove(int keycode, t_big *p)
{
	if (keycode == 0 && ifmove(p, ((p->map.ip - (cos(p->player.pa) * STEPS)) \
	/ SIZE), (p->map.jp + (sin(p->player.pa) * STEPS)) / SIZE))
	{
		p->map.ip -= cos(p->player.pa) * STEPS;
		p->map.jp += sin(p->player.pa) * STEPS;
	}
	if (keycode == 2 && ifmove(p, ((p->map.ip + (cos(p->player.pa) * STEPS)) \
	/ SIZE), (p->map.jp - (sin(p->player.pa) * STEPS)) / SIZE))
	{
		p->map.ip += cos(p->player.pa) * STEPS;
		p->map.jp -= sin(p->player.pa) * STEPS;
	}
	if (keycode == 53)
		exito(p);
	get_correct(p);
	if (keycode)
		ft_mooove2(keycode, p, 1);
	cast_rays(p);
	mini_map(p);
	return (0);
}
